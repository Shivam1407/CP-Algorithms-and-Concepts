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
    vector<int> a;

    f(i, 0, n)
    {
        int x;
        cin >> x;

        if (i and a.back() > x)
        {
            a.push_back(1);
        }
        a.push_back(x);
    }
    cout << a.size() << endl;
    f(i, 0, a.size())
    {
        cout << a[i] << " ";
    }
    cout << endl;
}


// lets take 
//         4 6 3 
//         now b1 = a1 = 4
//         for further operations A(i-1) <= Ai   
//         if a pair is taken such that  left <= right then it is okay 
//         if left > right then we will have to inset 1 in between them .