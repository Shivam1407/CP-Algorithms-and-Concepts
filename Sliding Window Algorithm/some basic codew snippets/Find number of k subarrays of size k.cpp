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
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k > n)
    {
        cout << 0 << endl;
        return;
    }
    vi a(n);
    in_1D_arr(a, n);

    int i = 0;
    int j = k - 1;
    ll ans = 0;

    ll sum = accumulate(a.begin(), a.begin() + k, 0);
    
    ll maxSum = INT_MIN;
    ll minSum = INT_MAX;
    while (j < n)
    {
        maxSum = max(maxSum, sum);
        minSum = min(minSum, sum);
        cout << "SubArr : " << i + 1 << " has sum : " << sum << endl;

        i++;
        j++;
        sum = sum - a[i - 1] + a[j];
        ans++;
    }

    cout << ans << endl;
    cout << "Max Sum : " << maxSum << endl;
    cout << "Min Sum : " << minSum << endl;
}