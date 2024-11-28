class Solution {
public:
    int robHelper(int house_no, vector<int>& nums, vector<int>& dp) {
        if(house_no < 0) return 0;
        if(dp[house_no] != -1) return dp[house_no];
        int robbed = robHelper(house_no - 2, nums, dp) + nums[house_no];
        int not_robbed = robHelper(house_no - 1, nums, dp);
        return dp[house_no] = max(robbed, not_robbed);
    }
    int robRecursive(vector<int>& nums) {
        int no_of_houses = nums.size();
        vector<int> dp(no_of_houses + 1, -1);
        return robHelper(no_of_houses - 1, nums, dp);
    }

    int robIterative(vector<int>& nums) {
        int no_of_houses = nums.size();
        vector<int> dp(no_of_houses + 1);
        dp[0] = nums[0];

        for(int i = 1; i < no_of_houses; ++i) {
            if(i - 2 >= 0) {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            else {
                dp[i] = max(dp[i - 1], nums[i]);
            }
        }

        return dp[no_of_houses - 1];
    }

    int robSpaceOptimized(vector<int>& nums) {
        int no_of_houses = nums.size();
        int prev = nums[0];
        int prev2, curr;

        for(int i = 1; i < no_of_houses; ++i) {
            if(i - 2 >= 0) {
                curr = max(prev, prev2 + nums[i]);
            }
            else {
                curr = max(prev, nums[i]);
            }
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};