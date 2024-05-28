#include <bits/stdc++.h>
#include <algorithm>
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
#define in_1D_arr(a, n, cnt) \
    f(i, 0, n)               \
    {                        \
        cin >> a[i];         \
        if (a[i] % 2 == 0)   \
            cnt++;           \
    }
typedef long long ll;
typedef vector<int> vi;
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
ll answer(ll n, ll k, vector<ll> &arr)
{
    ll cnt = k-1;
    f(i, 0, n)
    {
        if (arr[i] % k == 0)
        {
            return 0;
        }
        else
        {
            cnt = min(cnt, k - arr[i] % k);
        }
    }
    return cnt;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll cnt = 0;

    vector<ll> arr(n);
    in_1D_arr(arr, n, cnt);

    if(k != 4)
    {
        cout << answer(n, k, arr) << endl;
    }
    else{
        if(cnt >= 2)
        {
            cout << 0 << endl;
        }
        else if ( cnt ==1)
        {
            cout << min(answer(n,k,arr), 1LL) << endl;
        }
        else{
            cout << min(2LL, answer(n,k,arr)) << endl;
        }
    }

   

}