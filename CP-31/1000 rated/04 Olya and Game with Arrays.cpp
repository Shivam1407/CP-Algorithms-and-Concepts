#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(),v.end())
#define print_1D_arr(a,n)  for(ll i=0; i<n; i++),{cout<<a[i]<< ;} cout << endl;
#define in_1D_arr(a,n)                     f(i,0,n){cin>>a[i];}
#define all(v)  v.begin(),v.end()
#define pb push_back
typedef long long ll; 
typedef vector<int> vi;
typedef long long int  lli;
const int INF = 1e9 + 7;
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
    int n;
    cin >> n;

    int global_min = INF;
    vi second_min;

    while (n--)
    {
        int m;
        cin >> m;

        vi el(m);
        for(auto & e : el)
        {
            cin >> e;
        }

        int local_min = *min_element(all(el));
        global_min = min(global_min, local_min);

        el.erase(find(all(el), local_min));

        second_min.pb(*min_element(all(el)));
    }

    cout << accumulate(all(second_min), 0ll) + global_min - (*min_element(all(second_min))) << endl;
}