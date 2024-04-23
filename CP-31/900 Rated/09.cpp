#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
typedef long long ll; 


void solve();
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    f(i,0,n)
    {
        cin >> a[i];
    }
    int ans = 0, cur = 0;

    f(i,1,n)
    {
        cur = abs(i - a[i-1]);

        ans = __gcd(ans, cur);
    }
    cout << ans << endl;
    
}