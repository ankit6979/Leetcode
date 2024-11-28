class Solution {
public:
    // int canPartitionHelper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
    //     if(target < 0) return 0;
    //     if(idx == 0) {
    //         return target == 0;
    //     }
    //     else if(dp[idx][target] != -1) return dp[idx][target];
    //     int taken = canPartitionHelper(idx - 1, target - nums[idx], nums, dp);
    //     int not_taken = canPartitionHelper(idx - 1, target, nums, dp);
    //     return dp[idx][target] = taken || not_taken;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0);
        // vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        if(target % 2 == 1) return false;
        target = target / 2;
        // return canPartitionHelper(n - 1, target/2, nums, dp);

        vector<vector<bool>> dp(n, vector<bool> (target + 1, false));

        dp[0][0] = true;

        for(int i = 1; i < n; ++i) {
            for (int j = 0; j <= target; ++j) {
                bool taken = false;
                if (j >= nums[i]) taken = dp[i - 1][j - nums[i]];
                bool not_taken = dp[i - 1][j];

                dp[i][j] = taken || not_taken;
            }
        }

        return dp[n - 1][target];
    }
};