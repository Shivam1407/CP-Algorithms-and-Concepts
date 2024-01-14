#include <bits/stdc++.h>
using namespace std;

vector<int> TwoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(target - nums[i]) != mpp.end())
        {
            ans.push_back(mpp[target - nums[i]]);
            ans.push_back(i);
            return ans;
        }
        mpp[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
     TwoSum(nums, target);
    
}