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
int solve(string &s, string &e);
//--------------------------------------------------MAIN FUNCTION---------------------------------------------------------------------------------------------------------------------------------------------------
vector<string> arr = {"00", "25", "50", "75"};
int main() {
    ll t;
    cin >> t;
    while (t--) {
        int ans = INT_MAX;
        string s;
        cin >> s;
        for(auto e : arr)
        {
            ans = min(ans, solve(s, e));
        }
        cout << ans << endl;
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------SOLVE FUNCTION---------------------------------------------------------------------------------------------------------------------------------------------------
int solve(string &s, string &e) {

    int n = s.size()-1;
    int ans = 0;

    while (n>=0 and s[n] != e[1])
    {
        n--;
        ans++;
    }
    if(n < 0)
    {
        return INT_MAX;
    }
    n--;

    while (n >=0 and s[n] != e[0])
    {
        n--;
        ans++;
    }
    return (n < 0 ? INT_MAX : ans);
}