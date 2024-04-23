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
    int arr[n];
    int x = 0;
    f(i,0,n)
    {
        cin >> arr[i];
        x ^= arr[i];
    }
    if(x == 0)
    {
        cout << x << endl;
    }
    else{
        if(n%2 == 1)
        {
            cout << x << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}