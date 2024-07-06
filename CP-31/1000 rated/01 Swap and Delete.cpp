#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ans = 0;
        ll n = (ll)s.size();
        vector<int> v(2, 0);
        for (int i = 0; i < n; i++)
        {
            v[s[i] - '0']++;
        }

        for (int i = 0; i < n; i++)
        {
            if (v[!(s[i] - '0')] > 0)
            {
                v[!(s[i] - '0')]--;
            }
            else
            {
                ans = n - i;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}