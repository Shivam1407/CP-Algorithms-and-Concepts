// #include <bits/stdc++.h>
// using namespace std;

// #define f(i, a, b) for (auto i = (a); i < (b); ++i)
// #define rep(i, n) f(i, 0, n)
// #define rf(i, a, b) for (auto i = (a); i >= (b); --i)
// #define rrep(i, n) rf(i, (n)-1, 0)
// #define srt(v) sort(v.begin(), v.end())
// typedef long long ll;

// void solve();
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     string x, a;
//     cin >> x >> a;

//     if (x.find(a) != string::npos)
//     {
//         cout << 0 << endl;
//         return;
//     }

//     int cnt = 0;

//     for (int i = 0; i < m; i++)
//     {
//         x += x;
//         cnt++;
//         if (x.find(a) != string::npos)
//         {
//             cout << cnt << endl;
//             return;
//         }
//     }
//     cout << -1 << endl;
//     return;
// }

#include<bits/stdc++.h>
 
using namespace std;
 
int minOperationsToSubstring(string x, string s) {
    // Check if s is already a substring of x
    if (x.find(s) != string::npos) {
        return 0;
    }
    int n = x.length();
    int m = s.length();
 
 
    int count = 0;
    while (x.length() < n+m) {
        x += x;
        count++;
        if (x.find(s) != string::npos) {
            return count;
            break;
        }
    }
    
    return -1;
}
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n, m;
        string x, s;
        cin >> n >> m >> x >> s;
        
        int result = minOperationsToSubstring(x, s);
        cout << result << endl;
    }
 
    return 0;
}