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
bool static mycomp(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second > p2.second;
    }
    else
    {
        return p1.first < p2.first;
    }
}
void solve()
{
    ll n, p;
    #include<vector> // Include the necessary header file

    typedef pair<ll, ll> pll; // Define the type 'pll' as a pair of 'll' types
    typedef vector<pll> vpll; // Define the type 'vpll' as a vector of 'pll' types

    cin >> n >> p;
    vector<ll> arr(n), brr(n);
    vpll vp;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> brr[i];
    }
    for (int i = 0; i < n; i++)
    {
        vp.push_back({min(brr[i], p), arr[i]});
    }
    if (n == 1)
    {
        cout << p << endl;
        return;
    }
    sort(begin(vp), end(vp), mycomp);
    ll ans = p;
    ll rem = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        ans += min(vp[i].second, rem) * vp[i].first;
        rem -= min(rem, vp[i].second);
    }

    cout << ans << endl;
}