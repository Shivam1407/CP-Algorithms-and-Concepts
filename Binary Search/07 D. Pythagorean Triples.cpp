#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define print_1D_arr(a,n)  for(ll i=0; i<n; i++),{cout<<a[i]<< ;} cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
typedef long long ll; 
typedef vector<int> vi;
bool all_same_element_in_arr(ll *arr, ll n){for(ll i=0; i<n-1; i++){if(arr[i]!=arr[i+1]){return false;}}return true;}
void solve();
//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
void solve() {
    // ll n;
    // cin >> n;
    // ll pairs = 0;
    // f(i,1,n)
    // {
    //     f(j,i+1,n)
    //     {
    //         ll a = i;
    //         ll b = j;
    //         ll c = j + 1;

    //         if(c-(a*a)+b == 0 and a*a + b*b == c*c)
    //         {
    //             pairs++;
    //         }
    //     }
    // }

    // cout << pairs << endl;

    ll n;
    cin >> n;

    ll ans = 0;

    for (ll a = 3; a*a <= 2*n-1; a+=2)
    {
        ans++;
    }

   
    cout << ans << endl;
}