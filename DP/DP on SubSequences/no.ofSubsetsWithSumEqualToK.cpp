#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n) - 1, 0)
#define srt(v) sort(v.begin(), v.end())
#define print_1D_arr(a, n)      \
    for (ll i = 0; i < n; i++)  \
        , { cout << a[i] << ; } \
    cout << endl;
#define in_1D_arr(a, n) \
    f(i, 0, n) { cin >> a[i]; }
#define all(v) v.begin(), v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef long long int lli;
bool all_same_element_in_arr(ll *arr, ll n)
{
    for (ll i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
void solve();
void memoSolve();
void tableSolve();
void SpaceOptimization();

//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    solve();             // Recursion: O(2^n) time and O(n) space
    memoSolve();         // Memoization: O(n*k) time and O(n*k) space
    tableSolve();        // Tabulation: O(n*k) time and O(n*k) space
    SpaceOptimization(); // SpaceOptimized: O(n*k) time and O(k) space

    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------

int n = 9, k = 1;
vector<int> a = {0, 0, 0, 0, 0, 0, 0, 0, 1};
int recurr(int ind, int n, vi &a, int k)
{
    if (ind == 0)
    {
        if (k == 0 && a[0] == 0)
            return 2;
        if (k == 0 || k == a[0])
            return 1;
        return 0;
    }
    int notTake = recurr(ind - 1, n, a, k);
    int take = 0;
    if (k >= a[ind])
    {
        take = recurr(ind - 1, n, a, k - a[ind]);
    }

    return notTake + take;
}
void solve()
{

    cout << recurr(n - 1, n, a, k) << endl;
}

// Memoization Approach

int memo(int ind, int n, int k, vi &a, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (k == 0 && a[0] == 0)
            return 2;
        if (k == 0 || k == a[0])
            return 1;
        return 0;
    }

    if (dp[ind][k] != -1)
    {
        return dp[ind][k];
    }

    int notTake = memo(ind - 1, n, k, a, dp);
    int take = 0;
    if (k >= a[ind])
    {
        take = memo(ind - 1, n, k - a[ind], a, dp);
    }

    return dp[ind][k] = notTake + take;
}

void memoSolve()

{
    vector<vi> dp(n, vi(k + 1, -1));
    cout << "Memomization result : " << memo(n - 1, n, k, a, dp) << endl;
}

// Tabulation (Bottom-Up) approach

void tableSolve()
{
    vector<vi> dp(n, vi(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (a[0] <= k)
    {
        dp[0][a[0]] = 1;
    }

    if (a[0] == 0)
    {
        dp[0][0] = 2; 
    }

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= k; target++)
        {
            int notTake = dp[i - 1][target];
            int take = 0;
            if (target >= a[i])
            {
                take = dp[i - 1][target - a[i]];
            }

            dp[i][target] = notTake + take;
        }
    }

    cout << "Tabulation result : " << dp[n - 1][k] << endl;
}

// Space Optimization

void SpaceOptimization()
{
    vi prev(k + 1, 0), curr(k + 1, 0);

    prev[0] = curr[0] = 1;

    if(k >= a[0])
        prev[a[0]] = 1;
    
    f(i,1,n)
    {
        f(target,1,k+1)
        {
            int notTake = prev[target];
            int take = 0;

            if(k >= a[i])
            {
                take = prev[target - a[i]];
            }

            curr[target] = take + notTake;
        }
        prev = curr;
    }

    cout << "SpaceOptimization result : " << prev[k] << endl;
}