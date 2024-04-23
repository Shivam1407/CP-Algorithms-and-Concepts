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
    int a, b, n;
    cin >> a >> b >> n;
    int arr[n];
    ll ans = b;
    f(i,0,n)
    {
        cin >> arr[i];
        ans += min(arr[i], a - 1);
    }
    cout << ans << endl;

    // this question has pretty standard algorithm
    // we know that we have to delay the bombing by maxx time
    // to use the bomb optimallly we should use a tool everytime time == 1s;
    // so intially 
            // we will have 'b' time.
            // now we will add in min(arr[i], a-1)
            
}