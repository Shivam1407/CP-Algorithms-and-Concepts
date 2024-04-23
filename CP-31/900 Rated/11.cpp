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
    ll n;
    cin >> n;

    ll arr[n];
    f(i,0,n)
    {
        cin >> arr[i];
        if(arr[i] == 1) arr[i] += 1;
    }

    f(i,1,n)
    {
        if(arr[i] % arr[i-1] == 0)
        {
            arr[i] += 1;
        }
        else{
            continue;
        }
    }
    f(i,0,n)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// 4
// 6 3 5 5
// 7 4 6 6 


// adding 1 to the element if it is 1 becoz every number is divisible by 1
// then checking if the number is divisible by the previous number if yes then adding 1 to the number
// else continue