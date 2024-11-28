class Solution {
public:
    int findTargetSumWaysHelper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(idx == 0) {
            if(target == 0 && nums[0] == 0) return 2;
            if(abs(target) == nums[0]) return 1;
            return 0;
        }
        if (target < -1000 || target > 1000) return 0;
        if(dp[idx][target + 1000] != -1) {
            return dp[idx][target + 1000];
        }
        int pos = findTargetSumWaysHelper(idx - 1, target - nums[idx], nums, dp);
        int neg = findTargetSumWaysHelper(idx - 1, target + nums[idx], nums, dp);
        return dp[idx][target + 1000] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_nums = nums.size();
        vector<vector<int>> dp(total_nums, vector<int>(2002, -1));
        return findTargetSumWaysHelper(total_nums - 1, target, nums, dp);
    }
};
