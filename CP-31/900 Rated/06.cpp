#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i <= (b); ++i)
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
    ll n;
    cin >> n;

    if (n & 1)
        cout << "1" << endl;
    else
    {
        int leng = 0;

        f(i, 1, n)
        {
            if(n%i != 0)
            {
                
                break;
            }
            else
            {
                leng++;
            }
        }
        cout << leng << endl;
    }
}
