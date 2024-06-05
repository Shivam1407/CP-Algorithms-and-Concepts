#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n) - 1, 0)
#define srt(v) sort(v.begin(), v.end())
#define print_1D_arr(a, n)     \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << " ";   \
    }                          \
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
bool tableSolve();
bool SpaceOptimization();

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

int n = 4, k = 7;
vector<int> a = {2, 3, 1, 10};

// Recurssive approach
bool func(int k, int ind, vi &a)
{
    if (k == 0)
        return true;
    if (ind == 0)
        return a[ind] == k;

    bool notTake = func(k, ind - 1, a);

    bool take = false;

    if (a[ind] <= k)
    {
        take = func(k - a[ind], ind - 1, a);
    }

    return take || notTake;
}

void solve()
{
    cout << "Recursion: " << (func(k, n - 1, a) ? "true" : "false") << endl;
}

// Memoization approach
bool memo(int target, int ind, vi &a, vector<vi> &dp)
{
    if (target == 0)
        return true;
    if (ind == 0)
        return a[ind] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = memo(target, ind - 1, a, dp);
    bool take = false;

    if (target >= a[ind])
        take = memo(target - a[ind], ind - 1, a, dp);

    return dp[ind][target] = take | notTake;
}

void memoSolve()
{
    vector<vi> dp(n, vi(k + 1, -1));
    cout << "Memoization: " << (memo(k, n - 1, a, dp) ? "true" : "false") << endl;
}

// Tabulation (Bottom-Up) approach
bool tableSolve()
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    f(i, 0, n)
    {
        dp[i][0] = 1;
    }

    dp[0][a[0]] = 1;

    f(ind, 1, n)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (target >= a[ind])
            {
                take = dp[ind - 1][target - a[ind]];
            }

            dp[ind][target] = take | notTake;
        }
    }

    cout << "Tabulation: " << (dp[n - 1][k] ? "true" : "false") << endl;
}

// Space Optimization approach
bool SpaceOptimization()
{
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);

    prev[0] = curr[0] = true;

    if (a[0] <= k)
        prev[a[0]] = 1;

    f(ind, 1, n)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= a[ind])
            {
                take = prev[target - a[ind]];
            }

            curr[target] = take | notTake;
        }
        prev = curr;
    }

    cout << "SpaceOptimized: " << (prev[k] ? "true" : "false") << endl;
    return prev[k];
}
