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
    string s,t;
    cin >> s >> t;

    int n = s.length();

    vector<int> tfreq(26, 0);

    for(auto i : t)
    {
        tfreq[i - 'A']++;
    }
    string temp = "";
    rf(i,n-1,0)
    {
        if(tfreq[s[i] - 'A'] > 0)
        {
            tfreq[s[i] - 'A']--;
            temp += s[i];
        }
        
    }
    reverse(temp.begin(), temp.end());
    if(temp == t)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}