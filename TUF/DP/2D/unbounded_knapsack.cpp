class Solution{
public:
    // int knapSackHelper(int item, int rem_wt, int val[], int wt[], vector<vector<int>>& dp) {
    //     if (item == 0) {
    //         if (wt[0] <= rem_wt) {
    //             int pick = rem_wt / wt[0];
    //             return pick * val[0];
    //         }
    //         return 0;
    //     }
    //     else if(dp[item][rem_wt] != -1) return dp[item][rem_wt];
    //     int not_taken = knapSackHelper(item - 1, rem_wt, val, wt, dp) + 0;
    //     int taken = 0;
    //     if(rem_wt >= wt[item]) taken = knapSackHelper(item, rem_wt - wt[item], val, wt, dp) + val[item];
    //     return dp[item][rem_wt] = max(taken, not_taken);
    // }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> dp (N, vector<int> (W + 1, -1));
        // return knapSackHelper(N - 1, W, val, wt, dp);
        // vector<vector<int>> dp (N, vector<int> (W + 1, 0));
        vector<int> curr (W + 1, 0);
        vector<int> prev (W + 1, 0);
        for (int i = 0; i <= W; ++i) {
            prev[i] = (i / wt[0]) * val[0];
        }
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j <= W; ++j) {
                int not_taken = prev[j];
                int taken = 0;
                if (j >= wt[i]) taken = curr[j - wt[i]] + val[i];
                curr[j] = max(taken, not_taken);
            }
            prev = curr;
        }
        return prev[W];
    }
};