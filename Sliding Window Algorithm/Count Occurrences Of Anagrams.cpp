// PROBLEM: Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//

// APPROACH    --> we are given a pattern string.
// --> we will store the freq of pat in a hashtable.
// --> window size will be of that of pat.size().
// --> then we will store the characters of s in another hashtable (the loop will be of window size).
// if j-i+1 == k we wil do :-
//       -> if (frq of pattern == freq of window sized s) then we will do ans++;
///      ->then we will move the window to the next index and also will remove the previous occurence of s[i].
//                -> sfreq[s[i]-'a']--;
//                ->i++;
//       -> j++;

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
// ---------------------------------------------------------------------------------------------IstAPPROACH-------------------------------------------------------------------------------------------------------------------------------------------------
vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int>sfreq(26,0);
        vector<int>pfreq(26,0);

        int n = s.size();
        int k = p.size();

        for(auto c : p)
        {
            pfreq[c-'a']++;
        }
                                                                                   // SC ==  O(26*1) = O(1)
                                                                                   //TC == O(N) because of the while loop
        int i = 0, j = 0;

        while(j < n)
        {
            sfreq[s[j]-'a']++;

            if(j-i+1 == k)
            {
                if(sfreq == pfreq)
                {
                    ans.push_back(i);
                }

                sfreq[s[i]-'a']--;
                i++;
            }
            j++;
            
        }
        return ans;
    }