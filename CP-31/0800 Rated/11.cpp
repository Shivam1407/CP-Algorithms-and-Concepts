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
    
        solve();
    
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
        if(arr[i] < 0)
        {
            arr[i] = -arr[i];
        }
    }

    int mini = *min_element(arr, arr + n);
    cout << abs(mini) << endl;
}