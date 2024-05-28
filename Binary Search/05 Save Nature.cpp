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
#define in_1D_arr(a, n)    \
    f(i, 0, n)             \
    {                      \
        cin >> a[i];       \
        a[i] = a[i] / 100; \
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

bool poss(ll mid, ll a, ll b, ll x, ll y, ll k, vector<ll> &arr)
{
    ll n = arr.size();
    ll XY = 0, Y = 0, X = 0;

    for (int i = 1; i <= mid; i++)
    {
        if (i % a == 0 and i % b == 0)
        {
            XY++;
        }
        else if (i % a == 0)
        {
            X++;
        }
        else if (i % b == 0)
        {
            Y++;
        }
    }
    ll ans = 0;

    for (int i = 0; i < XY; i++)
    {
        ans += (arr[i] * (x + y));
    }
    for (int i = XY; i < XY + X; i++)
    {
        ans += (arr[i] * x);
    }
    for (int i = XY + X; i < XY + X + Y; i++)
    {
        ans += (arr[i] * y);
    }

    return ans >= k;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    in_1D_arr(arr, n);

    ll x, a, y, b, k;
    cin >> x >> a >> y >> b >> k;
   

        if (x < y)
    {
        swap(x, y);
        swap(a, b);
    }
    sort(arr.rbegin(), arr.rend());

    ll left = 0;
    ll right = n + 1;

    while (left + 1 < right)
    {
        ll mid = left + (right - left) / 2;

        if (poss(mid, a, b, x, y, k, arr))
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    if (right > n)
    {
       right = -1;
    }

    cout << right << "\n";
}