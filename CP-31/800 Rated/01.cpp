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
    int n, k;
    cin >> n >> k;

    int arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
    }

    if(is_sorted(arr, arr+n) || k>1)
    {
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}




// // the answer depends upon the value of k
// if k==1 then we can swap any elemts
// if k >1 then we can swap any elemnts 
// if array is already sorted then also we dont have to do anything