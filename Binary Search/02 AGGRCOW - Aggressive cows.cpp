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
bool helper(ll d, ll n, ll c, ll a[])
{
    ll cow = 1;
    ll prev = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] - prev >= d)
        {
            cow++;
            prev = a[i];
        }
    }
    return cow >= c;
}

void solve()
{
    ll n, c;
    cin >> n >> c;
    ll a[n];
    in_1D_arr(a, n);
    sort(a, a + n);

    ll low = 0;
    ll high = 1e12;

    while (low + 1 < high)
    {
        ll mid = (low + high) / 2;

        if (helper(mid, n, c, a))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << low << endl;
}

// we basically have to find the maximum distance between the cows such that the minimum distance between the cows is atleast mid
// if we can place the cows at a distance of mid then we can place the cows at a distance greater than mid as well
// so we can use binary search to find the maximum distance between the cows
// we can use the helper function to check if we can place the cows at a distance of mid
// we need to find the grestest of the optimized result