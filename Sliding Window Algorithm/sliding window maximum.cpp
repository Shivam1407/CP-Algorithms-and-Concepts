// we need to find a vector of all maximum element in each subarray of size k.






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

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        deque<int>dq;
        vector<int> ans;
        int n = nums.size();
        if(k>= n)
        {
            ans.push_back(*max_element(nums.begin(),nums.end()));
            return ans;
        }

        while(j<n)
        {
            while(!dq.empty() and dq.back()<nums[j])
            {
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if(j-i+1 == k)                            // TC == n;
            {
                ans.push_back(dq.front());             // SC == n

                if(dq.front() == nums[i])
                {
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return ans;
    }