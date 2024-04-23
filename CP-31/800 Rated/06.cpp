#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n)-1, 0)
#define srt(v) sort(v.begin(), v.end())
typedef long long ll;

void solve();
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mpp;

    f(i, 0, n)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }
    if (mpp.size() > 2)
    {
        cout << "NO\n" << endl;
    }
    else{
        if(abs(mpp.begin()->second - mpp.rbegin()->second) <= 1) // this the second case that dreq difference should be less than or equal to 1
        {
            cout << "yes" << endl;
        }
        else{
            cout << "NO\n";
        }
    }
}




//        if(abs(mpp.begin()->second - mpp.rbegin()->second) <= 1) // this the second case that dreq difference should be less than or equal to 1
//   12121 freqdif == 1
// 121212 freqdif == 0