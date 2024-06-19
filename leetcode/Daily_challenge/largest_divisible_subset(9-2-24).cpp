#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 1), hash(n);
        int maxi=1;
        int lastIdx = 0;
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(nums[i]%nums[prev]==0 && dp[prev]+1>dp[i]){
                    dp[i]=dp[prev]+1;
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIdx = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx];
            ans.push_back(nums[lastIdx]);
        }
        return ans;
    }
};