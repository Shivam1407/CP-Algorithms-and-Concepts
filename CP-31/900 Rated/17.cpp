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
    ll n;
    cin >> n;
    
    map<ll, ll> mp;
    f(i, 0, n)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    ll mx = 0;

    for(auto i : mp)
    
    {
        mx = max(mx, i.second);
    }

    int ans = 0;

    while(mx<n)
    {
        int d;
        d = min(n - mx, mx);
        ans += 1 + d;
        mx += d;
    }
    cout << ans << endl;
}