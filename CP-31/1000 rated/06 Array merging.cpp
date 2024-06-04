#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define print_1D_arr(a, n)     \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << " ";   \
    }                          \
    cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
#define all(v)  v.begin(),v.end() 
#define pb push_back
typedef long long ll;
typedef long long int lli;
typedef vector<lli> vi; 
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
    lli n;
    cin >> n;

    vi c(2 * n);

    for(auto &x : c)
    {
        cin >> x;
    }
    sort(all(c));


    ll maxi = 1;
    ll len = 1;

    for (int i = 1; i < c.size(); i++)
    {
        if(c[i-1] == c[i])
        {
            len++;
            maxi = max(maxi, len);

            
        }
        else
            len = 1;
    }
   
    cout << maxi << endl;
}