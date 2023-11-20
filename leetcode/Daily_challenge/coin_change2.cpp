class Solution {
public:
    int dp[5001][302];
    int coinCombinations(int amount, int pos, vector<int>& coins){
        if(amount==0){
            return 1;
        }
        else if(amount<0 || pos==coins.size()){
            return 0;
        }
        else if(dp[amount][pos] != -1){
            return dp[amount][pos];
        }
        else{
            int ans = 0, curr_amt=amount;
            while(curr_amt>=0){
                ans += coinCombinations(curr_amt, pos+1, coins);
                curr_amt -= coins[pos];
            }
            return dp[amount][pos] = ans;
        }
    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return coinCombinations(amount, 0, coins);
    }
};