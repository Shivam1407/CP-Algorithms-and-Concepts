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
int memo(int ind, int target, vi &a, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;
    if (ind == 0)
    {
        if (target == a[0])
            return 1;
        else
            return 0;
    }
    if(dp[ind][target] != -1)
    {
        return dp[ind][target];
    }

    int notTake = memo(ind - 1, target, a, dp);
    int take = 0;

    if(target >= a[ind])
    {
        take = memo(ind - 1, target - a[ind], a, dp);
    }

    return dp[ind][target] = notTake + take;
    
}

int table( int target, vi &a)
{
    int n = a.size();
    vector<vi> dp(n, vi(target + 1, 0));
    if(a[0] == 0)
    {
        dp[0][0] = 2;
    }
    else {
        dp[0][0] = 1;
    }
    if(a[0] != 0 and a[0] <= target)
    {
        dp[0][a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notTake = dp[i - 1][t];
            int take = 0;
            if(t >= a[i])
            {
                take =dp[i - 1][t - a[i]];
            }
            dp[i][t] = take + notTake;
        }
    }
    return dp[n - 1][target];
}

int space(int target, vi&a)
{
    int n = a.size();
    vector<int> prev(target + 1, 0), curr(target + 1, 0);

    if(a[0] == 0)
    {
        prev[0] = 2;
    }
    else {
        prev[0] = 1;
    }
    if(a[0] != 0 and a[0] <= target)
    {
        prev[a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int t = 0; t <= target; t++)
        {
            int notTake = prev[t];
            int take = 0;
            if(t >= a[i])
            {
                take = prev[t - a[i]];
            }
            curr[t] = take + notTake;
        }
        prev = curr;
    }
    return prev[target];
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    in_1D_arr(a, n);

    int sum = accumulate(all(a), 0);
    if ((sum - k) % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }
    if (sum < k)
    {
        cout << 0 << endl;
        return;
    }
    int target = (sum - k) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    cout << memo(n - 1, target, a, dp) << endl;
    cout << table( target, a) << endl;
    cout << space( target, a) << endl;
}