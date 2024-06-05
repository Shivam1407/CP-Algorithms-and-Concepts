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
#define in_1D_arr(a, n) \
    f(i, 0, n) { cin >> a[i]; }
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

//--------------------------------------------------MAIN---------------------------------------------------------------------------------------------------------------------------------------------------
// Space Optimization
bool SpaceOptimization(int n, int k, vi &a)
{
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);

    prev[0] = curr[0] = true;

    if (k >= a[0])
        prev[a[0]] = 1;

    f(ind, 1, n)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (target >= a[ind])
            {
                take = prev[target - a[ind]];
            }

            curr[target] = take | notTake;
        }
        prev = curr;
    }

    cout << "SpaceOptimized: " << (prev[k] ? "true" : "false") << endl;
    return prev[k];
}

// Recursion: false
// Memomization: false
// Tabulation: false
// SpaceOptimized: false

bool canPartition(vi &a, int n)
{
    int sum = accumulate(all(a), 0);
    if (sum % 2 != 0)
    {
        return false;
    }

    int target = sum / 2;

    return SpaceOptimization(n, target, a);
}
int main()
{
    int n = 4;
    vi a = {20, 5, 10, 5};

    bool result = canPartition(a, n);
    cout << "Can partition: " << (result ? "true" : "false") << endl;

    return 0;
}
//--------------------------------------------------SOLVE---------------------------------------------------------------------------------------------------------------------------------------------------
