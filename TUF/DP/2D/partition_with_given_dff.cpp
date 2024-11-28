class Solution {
  public:
    int mod = 1e9 + 7;
    // int countPartitionsHelper(int idx, int target, vector<int>& arr, vector<vector<int>>& dp) {
    //     if (idx == 0) {
    //         if(target == 0 && arr[0] == 0) return 2;
    //         else if (target == arr[0] || target == 0) return 1;
    //         return 0;
    //     }
    //     if (dp[idx][target] != -1) return dp[idx][target];
    //     int not_taken = countPartitionsHelper(idx - 1, target, arr, dp) % mod;
    //     int taken = 0;
    //     if (target >= arr[idx]) taken = countPartitionsHelper(idx - 1, target - arr[idx], arr, dp) % mod;
    //     return dp[idx][target] = (taken + not_taken) % mod;
    // }
    int countPartitions(int n, int d, vector<int>& arr) {
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if ((total_sum + d) % 2 != 0 || total_sum < d) return 0;
        int target = (total_sum + d) / 2;
        // vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        // return countPartitionsHelper(n - 1, target, arr, dp);
        vector<vector<int>> dp(n, vector<int> (target + 1, 0));
        
        for (int i = 0; i <= target; ++i) {
            if(i == 0 && arr[0] == 0) dp[0][i] = 2;
            else if (i == arr[0] || i == 0) dp[0][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= target; ++j) {
                int not_taken = dp[i - 1][j] % mod;
                int taken = 0;
                if (j >= arr[i]) taken = dp[i - 1][j - arr[i]] % mod;
                dp[i][j] = (taken + not_taken) % mod;
            }
        }
        
        return dp[n - 1][target];
    }
};