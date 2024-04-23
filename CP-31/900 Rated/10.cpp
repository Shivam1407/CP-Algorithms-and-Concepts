#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i <= (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(), v.end())
typedef long long ll;

void solve();
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

void solve()
{
    ll n;
    cin >> n;

    ll q;
    cin >> q;

    vector<ll> a(2 * 1e5 + 1);
    vector<ll> pref(2 * 1e5 + 1);
    f(i, 1, n)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;

        ll sum = 0;
        sum = pref[n] - (pref[r] - pref[l - 1]) + (r - l + 1) * k;

        if (sum % 2 == 1)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

// 15 1 9 5 9 12 10 12 14 10 13 12 9 9
// 9 11 5
// 15 1 9 5 9 12 10 12 5 5 5 12 9 9