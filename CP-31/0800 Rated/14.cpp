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
    int a, b, c;
    cin >> a >> b >> c;

    if(c %2 == 0)
    {
        if(a > b)
        {
            cout << "First\n";
        }
        else{
            cout << "Second\n";
        }
    }
    else{
        if(b>a)
        {
            cout << "Second\n";
        }
        else{
            cout << "First\n";
        }
    }
}