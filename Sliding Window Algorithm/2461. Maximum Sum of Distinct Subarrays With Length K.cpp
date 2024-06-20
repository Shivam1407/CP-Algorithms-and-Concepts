// problem statement: we need to find the maximum sum of sub array with distinct elements with size K

// Approach : we would be taking two pointers so as to mark the size of window.
// Initialize a map mpp to store the frequency of elements within the current sliding window.
// we will iterate over the array untill the end pointer reaches n.
// until j-i+1 is less than k then we will keep on doing j++;
// now we will keep adding the answer to sum untill it reaches K.
// after it reches k
// we will do
//                         maxi = max(max,sum);
// then we will push the window further and do i++ and j++
// Update the frequency of the removed element in the map mpp and remove it from the map if its frequency becomes 0.

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
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        solve(nums, k);
    }
    return 0;
}

long long solve(vector<int> &nums, int k)
{
    unordered_map<long long, long long> mpp;
    long long j = 0;
    long long i = 0;
    long long maxi = 0;
    long long sum = 0;
    while (j < nums.size())
    {
        mpp[nums[j]]++;
        sum += nums[j];
        if (j - i + 1 < k) // till window size in not reached , move on.
        {
            j++;
        }
        // window size reach , find maxi if freq size is equal to k
        else if (j - i + 1 == k)
        {
            if (mpp.size() == k)
                maxi = max(maxi, sum); // it basically sees how many distinct elemnts ae presents in the map
            sum -= nums[i];            // now, move to next window by removing the calculation for i
            mpp[nums[i]]--;
            if (mpp[nums[i]] == 0)
                mpp.erase(nums[i]); // erase it from freq     //[9,9,9,1,2,3] if condition nhi lagaya toh iss case me error de dega becoz all occurences of 9 will get deleted wrong max sum will get printed
            // going to next window
            i++;
            j++;
        }
    }
    return maxi;
}