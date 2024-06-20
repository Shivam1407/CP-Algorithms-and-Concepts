//  Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

// APPROACH:
// --> we want first negative number so we would be storing all the negative nums in a que from starting .
// --> we would iterate till j-i+1 < k
// --> as we find a negative number we will push it in the que.
// --> when j-i+1 == k then we will check if the que is empty : ans.pushback(0) else we will ans.push_back(q.front()) then if A[i] == q.front( then we will q.pop())

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

//  ------------------------------------------------------------------ Ist APPROACH ----------------------------------------------------------------------
vector<long long> solve(long long int A[], long long int N, long long int K)
{
    long long i = 0, j = 0;

    queue<long long> q;
    vector<long long> ans;

    while (j < N)
    {
        if (A[j] < 0)
        {
            q.push(A[j]);
        }
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            if (q.empty())
            {                                                         // TIME COMPLEXITY == o(N)
                ans.push_back(0);                                     // SPACE  COMPlexity == O(K)
            }

            else
            {
                ans.push_back(q.front());
                if (A[i] == q.front())
                {
                    q.pop();
                }
            }

            i++;
            j++;
        }
    }
    return ans;
}

// ------------------------------------------------------------------------IInd Approach ---------------------------------------------------------------------------------------
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{

    long long i = 0, j = 0;

    vector<long long> ans;

    while (j < N)
    {
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            long long k = i;
            bool flag = 0;
            while (k <= j)
            {
                if (A[k] < 0)
                {
                    ans.push_back(A[k]);
                    flag = 1;
                    break;
                }
                k++;
            }

            if (flag == 0)
            {
                ans.push_back(0);
            }
            i++;
            j++;
        }
    }
    return ans;
}

// this approac is giving TLE  for some test case but stack space is O(1);