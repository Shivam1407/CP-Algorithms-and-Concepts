#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
typedef long long ll; 
#define prnt(y) {cout << "YES" << endl; return;}


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
    
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    int a = arr[0], b = arr[1], c = arr[2];

    int newA = 2 * b - c;
    if(newA>=a and   newA%a==0 and newA != 0)
        prnt(y);

    int newB = a + (c - a) / 2;
    if(newB>=b and (c-a)%2 == 0 and  newB%b==0 and newB != 0)
        prnt(y);

    int newC = a + 2*(b - a);
    if(newC>=c and newC%c==0 and newC != 0)
        prnt(y);

    cout << "NO" << endl;
}