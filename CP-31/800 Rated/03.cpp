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

    string s;
    cin >> s;

    size_t pos = s.find("...");

    if(pos != string::npos)
    {
        cout << 2 << endl;
    }
    else{
        int cnt = 0;
        for(auto c:s)
        {
            if(c == '.')
            {
                cnt++;
            }

        }
        cout << cnt << endl;
    }
}


// // what is happening??
// // .###...##
// now if we have 3 consecutive ... then the no. of operation is 2 becoz when we fill i+1 and i-1 then i gets filled by itself.
// uske baad we bas have shift the water from here to there and so on.

// ..##..#
// now if this is the case then we wont be having the 3 consecutive case so we have to individually fill all the empty places.