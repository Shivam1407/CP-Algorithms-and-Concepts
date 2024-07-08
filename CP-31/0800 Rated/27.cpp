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
    int arr[n];
    int cnt = 0;
    f(i,0,n)
    {
        cin >> arr[i];
        if(arr[i] == 2)
        {
            cnt++;
        }
    }
    if(cnt % 2 != 0)
    {
        cout << "-1" << endl;
        return;
    }
    int two = 0;
    f(i,0,n)
    {
        if(arr[i] == 2)
        {
            two++;
        }
        if(two == cnt/2)
        {
            cout << i+1 << endl;
            break;
        }
    }

}