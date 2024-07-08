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

    int ans = 1, cur = 1;
    f(i,1,n)
    {
        if(s[i] != s[i-1])
        {
            cur = 1;
        }
        else cur++;

         ans = max(ans, cur);
    }
   

    cout << ans + 1 << endl;
}


// PROBLEM LINK: https://codeforces.com/problemset/problem/1837/B
// PROBLEM NAME: 1837B. Balanced Substring

// Solution:
// what we have is a string of > and < characters.
// whenever s[i] != s[i-1] we will keep the cur = 1;
// else we will increment the cur.
// at each step we will do ans = max ( cur , ans )

// TEST CASE 
                       // <<<><
                       // LENGHT IS 5 SO WE take our range from 0,5
                       // s[1] = s[0] so cur = 2    ans = 2
                       // s[2] = s[1] so cur = 3    ans = 3
                       // s[3] != s[2] so cur = 1   ans = 3
                          // s[4] = s[3] so cur = 2 ans = 3
                            // answer would be 3+1 = 4
