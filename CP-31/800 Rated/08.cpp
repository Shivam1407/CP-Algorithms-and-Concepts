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
    int n,k;
    cin >> n >> k;
        int ys = 0;


    f(i,0,n)
    {
        int a;
        cin >> a;
        if(a == k)
            ys = 1;
    }
    if(ys)
    {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

// agar array me k hoga then for some sub segment it will surely be equal to the most common number