#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i <= (b); ++i)
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
    ll n, k, x;
    cin >> n >> k >> x;

    ll sum1 = k * (k + 1) / 2;
    ll sum2 = n * (n + 1) / 2;
    ll tot = n - k;
    ll sum3 = sum2 - (tot * (tot + 1) / 2);

    if(x >= sum1 and x<= sum3)
    {
        cout << "YES\n";
    }
    else {
        cout << "NO" << endl;
    }
}