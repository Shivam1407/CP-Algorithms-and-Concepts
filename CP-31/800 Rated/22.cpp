#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
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
    ll n, k;
    cin >> n >> k;
    bool found = 0;

    f(y, 0, 2)
    {
        if ((n - k * y) >= 0 and (n - k * y) % 2 == 0)
        {
            cout << "YES" << endl;
            found = 1;
            break;
        }
    }
    if (found == 0)
        cout << "NO" << endl;
}