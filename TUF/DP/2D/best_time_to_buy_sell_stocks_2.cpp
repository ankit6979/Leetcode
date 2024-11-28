class Solution {
public:
    int maxProfitHelper(int day, int is_bought, vector<int>& prices, vector<vector<int>>&dp) {
        if(day == prices.size()) {
            return 0;
        }
        if(dp[day][is_bought] != -1) return dp[day][is_bought];
        int buy = 0, sell = 0, hold = 0;
        if(is_bought == 1) {
            sell = maxProfitHelper(day + 1, 0, prices, dp) + prices[day];
            hold = maxProfitHelper(day + 1, 1, prices, dp);
        }
        else {
            buy = maxProfitHelper(day + 1, 1, prices, dp) - prices[day];
            hold = maxProfitHelper(day + 1, 0, prices, dp);
        }
        return dp[day][is_bought] = max({buy, sell, hold});
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return maxProfitHelper(0, 0, prices, dp);
    }
};


/*
Optimized Greedy
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_profit = 0;
        int buy_price = prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            if(prices[i] < prices[i - 1]) {
                total_profit += (prices[i - 1] - buy_price);
                buy_price = prices[i];
            }
        }
        total_profit += (prices[prices.size() - 1] - buy_price);
        return total_profit;
    }
};