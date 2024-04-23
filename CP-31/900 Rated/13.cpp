#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i <= (b); ++i)
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
    ll n;
    cin >> n;

    ll arr[n+1] = {0};
    int cnt = 0;
    f(i,1,n)
    {
        cin >> arr[i];
        if(arr[i-1] == 0 and arr[i] != 0)
            cnt++;
    }
    cnt = min(cnt, 2);
    cout << cnt<< endl;
}