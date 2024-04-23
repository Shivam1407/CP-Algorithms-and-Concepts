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
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    f(i,0,n)
    {
        cin >> arr[i];
    }
    srt(arr);

    if(arr[0] == arr[n-1])
    {
        cout << "-1\n";
        return;
    }
    else{
        int it = 0;
        while(arr[it] == arr[0])
            it++;

        cout << it << " " << n - it << endl;
        f(i, 0, it) cout << arr[i] << " ";
        cout << endl;
        f(j, it, n) cout << arr[j] << " ";
        cout << endl;
    }
}

// Ci should be such that it is not a divisor of Bj;
// sorted the array 
// so we checked it is a reccuring array if not then we took the else condition as divisor <= Divident so if we take the sammlest number in the array in B then C would never divide B