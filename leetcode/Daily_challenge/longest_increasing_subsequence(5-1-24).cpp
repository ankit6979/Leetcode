#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int calcLen(int curr_idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp){
        if(curr_idx==nums.size()){
            return 0;
        }
        if(dp[curr_idx][prev_idx+1] != -1){
            return dp[curr_idx][prev_idx+1];
        }
        int len = calcLen(curr_idx+1, prev_idx, nums, dp);
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx]){
            len = max(len, calcLen(curr_idx+1, curr_idx, nums, dp)+1);
        }
        return dp[curr_idx][prev_idx+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        return calcLen(0, -1, nums, dp);
    }
};