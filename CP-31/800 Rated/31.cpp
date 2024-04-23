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
    int n, a, b;
    cin >> n >> a >> b;
    if(a+b >= n-1)
    {
        if(a == n and b == n)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO\n";
        }

    }
    else{
        cout << "YES" << endl;
    }
}