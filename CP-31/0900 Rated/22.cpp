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
//--------------------------------------------------MAIN FUNCTION---------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//-------------------------------------------------------------------------------------------------SOLVE FUNCTION---------------------------------------------------------------------------------------------------------------------------------------------------
void solve() {
    int n;
    cin >> n;
    ll arr[n];
    in_1D_arr(arr, n);

    ll sum = accumulate(arr, arr+n, 0);
    ll seqSum = 0;
    int NofSubSeq = 0;

    f(i, 0, n)
    {
        f(j, i, n)
        {
            seqSum += arr[j];
            if(seqSum == sum-1)
            {
                NofSubSeq++;
                seqSum = 0;
            }
        }
    }
    cout << NofSubSeq << endl;
            
}