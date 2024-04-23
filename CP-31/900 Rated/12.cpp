#include<bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i > (b); --i)
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

    int arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
    }
    int maxi = 0;
    int mini = 1e6;
    int maxi1 = 0;

    f(i,0,n-1)
    {
        mini = min(mini, arr[i]);
    }
    maxi = max(maxi, arr[n - 1] - mini);
    for(int i = n - 1; i > 0; i--)
    {
        maxi1 = max(maxi1, arr[i]);
    }
    maxi = max(maxi, maxi1 - arr[0]);

    f(i,0,n-1)
    {
        maxi = max(maxi, arr[i] - arr[i + 1]);
    }
    cout << maxi << endl;
}

/// three cases
//1. we will find the minimum element in range [0,n-2] and then subtract it with n-1th element
//2. we will find the maximum element in range [1,n-1] and then subtract it with 0th element
//3. edge case we will fin the maximum difference between the adjacent elements in the array  becoz
                        // 2 1  8 1
                        // in this we can rotate the array to become 1 2 1 8 then the answer will be 7
                        // so we will find the difference between the adjacent elemnts.