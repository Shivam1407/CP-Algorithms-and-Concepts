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
    int n, k;
    cin >> n >> k;
    vi a(n);
    in_1D_arr(a, n);

    int i = 0;
    int j = k - 1;
   
    ll curr = 0;
    unordered_map<int, int> mp;

    // for (int i = 0; i < k; i++)
    // {
    //     if(mp[a[i]] == 0)
    //         curr++;
    //     mp[a[i]]++;
        
        
    // }

    // while(j < n)
    // {
    //     cout << " Max Dis ele in subarray: " << i+1 << " is " << curr << endl;
    //     i++;
        

    //     mp[a[i-1]]--;
    //     if (mp[a[i-1]] == 0)
    //     {
    //         curr--;
    //     }
        
    //     j++;
    //     if (mp[a[j]] == 0)
    //     {
    //         curr++;
    //     }
    //     mp[a[j]]++;

    // }
    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(mp[a[i]] == 0)
            curr++;
        mp[a[i]]++;    

        if(i >= k)
        {
            mp[a[i - k]]--;
            if(mp[a[i - k]] == 0)
                curr--;
            
        }

        if(i >= k - 1)
        {
            ans = max(ans, curr);
            cout << " Max Dis ele in subarray: " << i - k + 2 << " is " << curr << endl;
            
        }
        

    }
    cout << ans << endl;
}