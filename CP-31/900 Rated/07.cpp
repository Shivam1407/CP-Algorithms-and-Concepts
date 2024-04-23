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
    int n, k;
    cin >> n >> k;

    int arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int ans = 1;
    int cnt = 1;

    f(i,0,n-1)
    {
        if(arr[i+1] - arr[i] > k)
        {
            cnt = 1;
        }
        else{
            cnt++;
            
        }
        ans = max(ans, cnt);
       
    }
    cout << ans << endl;
}