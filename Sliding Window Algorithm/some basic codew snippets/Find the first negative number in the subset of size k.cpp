#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (auto i = (a); i < (b); ++i)
#define rep(i, n) f(i, 0, n)
#define rf(i, a, b) for (auto i = (a); i >= (b); --i)
#define rrep(i, n) rf(i, (n) - 1, 0)
#define srt(v) sort(v.begin(), v.end())
#define print_1D_arr(a, n)     \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << " ";   \
    }                          \
    cout << endl;
#define in_1D_arr(a, n)        \
    for (ll i = 0; i < n; i++) \
    {                          \
        cin >> a[i];           \
    }
#define all(v) v.begin(), v.end()
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef long long int lli;

bool all_same_element_in_arr(ll *arr, ll n)
{
    for (ll i = 0; i < n - 1; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void solve();

//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
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

//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
void solve()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    in_1D_arr(a, n);

    deque<int> q;

    for (int i = 0; i < n; i++)
    {
        // Add the current element if it's negative
        if (a[i] < 0)
        {
            q.push_back(i);
        }

        // Remove elements that are out of this window
        if (!q.empty() && q.front() <= i - k)
        {
            q.pop_front();
        }

        // Print the first negative number in the current window
        if (i >= k - 1)
        {
            if (!q.empty())
            {
                cout << "First negative number in subarray [" << i - k + 1 << ", " << i << "] is: " << a[q.front()] << endl;
            }
            else
            {
                cout << "No negative number in subarray [" << i - k + 1 << ", " << i << "]" << endl;
            }
        }
    }
}
