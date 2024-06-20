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
//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
int recurr( int w, vector<int> wt, vector<int> val, int ind) // O(2^n) time  and O(n) stack space
{
    if (ind == 0)
    {
        if (wt[0] <= w)
        {
            return val[0];
        }
        else return 0;
    }

    int notTake = 0 + recurr( w, wt, val, ind - 1);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = val[ind] + recurr(w - wt[ind], wt, val, ind - 1);
    }
    return max(take, notTake);
}


int memo(int w, vector<int> wt, vector<int> val, int ind, vector<vector<int>> &dp) //(O(n*w) time and O(n*w) space + O(n) stack space, due to memoization we are storing the result of each subproblem in dp array)
{
    if(ind == 0)
    {
        if(wt[0] <= w)
        {
            return val[0];
        }
        return 0;
    }
    if(dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notTake = 0 + memo(w, wt, val, ind - 1, dp);
    int take = INT_MIN;
    if(wt[ind] <= w)
    {
        take = val[ind] + memo(w - wt[ind], wt, val, ind - 1, dp);
    }
    return dp[ind][w] = max(take, notTake);
}

int table(int w, vector<int> wt, vector<int> val, int n) // (O(n*w) time and O(n*w) space)

{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = 0; i <= w; i++)
    {
        dp[0][i] = val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= w; W++)
        {
            int notTake = 0 + dp[ind - 1][W];
            int take = INT_MIN;

            if (wt[ind] <= W)
            {
                take = val[ind] + dp[ind - 1][W - wt[ind]];
            }
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}
int space(int w, vector<int> wt, vector<int> val, int n) // O(n*w) time and O(w) space

{
    vector<int> prev(w + 1, 0);
    vector<int> curr(w + 1, 0);
    for (int i = wt[0]; i <= w; i++)
    {
        prev[i] = val[0];
    }

    for (int i = 1; i < n; i++)
    {
       
        for (int j = 0; j <= w; j++)
        {
            int notTake = 0 + prev[j];
            int take = INT_MIN;
            if(wt[i] <= j)
            {
                take = val[i] + prev[j - wt[i]];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}

void solve()
{
    int n, w;
    cin >> n >> w;
    vector<int> wt(n), val(n);
    f(i, 0, n)
    {
        cin >> wt[i];
    }
    f(i, 0, n)
    {
        cin >> val[i];
    }
    vector<vector<int>> dpm(n + 1, vector<int>(w + 1, -1));
    vector<vector<int>> dpt(n , vector<int>(w + 1, 0));

    cout << recurr( w, wt, val, n - 1) << endl;
    cout << memo(w, wt, val, n - 1, dpm) << endl;
    cout << space(w, wt, val, n ) << endl;
    cout << table(w, wt, val, n) << endl;
}