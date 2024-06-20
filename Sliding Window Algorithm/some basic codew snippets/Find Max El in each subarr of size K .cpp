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
    ll n, k;
    cin >> n >> k;

    vi a(n);
    in_1D_arr(a, n);
    vector<ll> ans;
    // multiset<ll> st;

    // for (int i = 0; i < n; i++)
    // {
    //     st.insert(a[i]);

    //     if(i >= k)
    //     {
    //         st.erase(st.find(a[i - k]));
    //     }

    //     if(i >= k-1)
    //     {
    //         ll largest = *st.rbegin();
    //         ans.push_back(largest);
    //     }
    // }

    // f(i, 0, ans.size())
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;

    deque<ll> dq;

    for (ll i = 0; i < k; i++)
    {
        while (!dq.empty() and a[i] >= a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    f(i, k, n)
    {
        ans.push_back(a[dq.front()]);
        while (!dq.empty() and dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while(!dq.empty() and a[i]>= a[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    ans.push_back(a[dq.front()]);

    f(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
}