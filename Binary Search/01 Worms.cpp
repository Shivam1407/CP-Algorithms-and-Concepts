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
void solve()
{
    int n, m;
    cin >> n;
    int a[n];
    in_1D_arr(a, n);

    int pre[n];
    pre[0] = a[0];
    f(i, 1, n)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    cin >> m;

    for (ll i = 0; i < m; i++)
    {
        ll target;
        cin >> target;
        // ll ans = 0;
        // ll low = 0;
        // ll high = n - 1;

        // while (low <= high)
        // {
        //     ll mid = (low + high) / 2;
        //     if (pre[mid] > target)
        //     {
        //         if (pre[mid - 1] < target)
        //         {
        //             ans = mid + 1;
        //             break;
        //         }
        //         high = mid - 1;
        //     }
        //     else if (pre[mid] < target)
        //     {
        //         if (pre[mid + 1] > target)
        //         {
        //             ans = mid + 1;
        //             break;
        //         }
        //         low = mid + 1;
        //     }
        //     else{
        //         ans = mid + 1;
        //         break;
        //     }
        // }
        int ind = lower_bound(pre, pre + n, target) - pre;
        cout << ind+1 << endl;
    }
}