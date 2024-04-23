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
    int n, x;
    cin >> n >> x;

    int ans = 0;
    int prev = 0;

    f(i,0,n)
    {
        int a;
        cin >> a;

        ans = max(ans, a - prev);
        prev = a;
    }

    ans = max(ans, 2 * (x - prev));

    cout << ans << endl;
}


// chl kya rha hai ???


// 0 1 2 3 4 5 6 7 
//   _ _     _


//   startting from 0 it will go to 1 on then it get refueled.    we can say that atleast 1-0  should be the V;
// || ly it will go from 1 to 2 atleast 2 - 1;
// it will go 2 to3 then 3to4 then 4to 5,  5 is where it will get refilled so the tank should atleast be 5 - 2;

// now with a fulled tank it will go from 5 to 7 and then come back from 7 to 5 so it should atleast be 2(7 - 5);