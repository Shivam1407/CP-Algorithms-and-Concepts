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
    int a, b;
    cin >> a >> b;
    int xk, yk;
    cin >> xk >> yk;
    int xq, yq;
    cin >> xq >> yq;

    vector<pair<int, int>> dir;

    dir = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {-b, -a}, {-b, a}, {b, a}, {b, -a}};

    set<pair<int, int>> st1, st2;

    for(auto d:dir)
    {
        int x = xk + d.first;
        int y = yk + d.second;

        st1.insert(make_pair(x, y));

        x = xq + d.first;
        y = yq + d.second;

        st2.insert(make_pair(x, y));
    }

    int ans = 0;
    for(auto pos : st1)
    {
        if(st2.find(pos) != st2.end())
        {
            ans++;
        }
    }

    cout << ans << endl;
}



// // a knight can move in eight directions 

// //                 ___ ___
// //                    |
// //                 |___| 
// //                 |   |
// // that can be a,b a,-b -a,b -a,-b  
// //             b,a b,-a -b,a  -b,-a

// // then we will one by one add the pairs to the following coordinates.
// where ever we fin the same between king and queen so we will do ans++;
