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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b <= d && 0 <= a + d - b - c)
    {
        cout << (d - b) + (a + d - b - c) << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}




// there can be various paths but the shortest path can only be acheived by on method.

// so 
//      (a,b) -> (a+d-b, d)
//      now to go c steps we will just -c from above 
//      (a+d-b,d) -> (a+d-b-c, d)

//      conditions are (x-1,y) and (x+1,y+1)

//      so first we will go to d then we will com back for c
//      only possible if d>=b and a+d-b-c>=0