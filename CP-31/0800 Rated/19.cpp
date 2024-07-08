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
    int counter = 0;
    f(i,0,n)
    {
        cin >> arr[i];
        if( arr[i] == -1)
        {
            counter++;
        }
    }
    int m = arr.size();
    if(counter <= m/2 and counter %2 == 0 )
    {
        cout << 0 << endl;
    }else{
        int noOfOperations = 0;

        if(counter > m/2)
        {
            noOfOperations += counter - m / 2;
            counter -= noOfOperations;
        }
        if(counter %2 != 0)
        {
            noOfOperations += 1;
        }

        cout << noOfOperations << endl;
    }

}