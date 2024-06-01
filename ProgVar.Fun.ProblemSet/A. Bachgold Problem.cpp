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
    
        solve();
    
    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
void solve() {

    ll n;
    cin >> n;

    if(n%2 == 0)
    {
        cout << n / 2 << endl;
        f(i,0,n/2)
        {
            cout << 2 << " ";
        }

        cout << endl;
    }

    else{
        cout << n / 2 << endl;
        f(i,0,n/2-1)
        {
            cout << 2 << " ";
        }
        cout << 3 << endl;
    }
}