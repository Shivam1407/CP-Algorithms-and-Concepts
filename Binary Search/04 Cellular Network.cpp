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

    solve();

    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------

bool possible(ll r, ll a[], ll b[], ll n, ll m)
{
    ll i = 0, j = 0;

    while (i < n and j < m)
    {
        if (abs(a[i] - b[j]) <= r)
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    if (i == n)
        return true;
    return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    in_1D_arr(a, n);
    in_1D_arr(b, m);

    ll ans = -1;

    ll low = 0;
    ll high = 2e9;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (possible(mid, a, b, n, m))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
}