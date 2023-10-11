#include<bits/stdc++.h>
using namespace std;
/*
DP solution O(n^2)
*/
class Solution {
public:
    int maxProduct(int *dp, int num){
        if(num == 1){
            return 1;
        }
        else if(dp[num] != -1){
            return dp[num];
        }
        else{
            return dp[num] = max({
                1*maxProduct(dp, num-1),
                2*maxProduct(dp, num-2),
                3*maxProduct(dp, num-3),
                4*maxProduct(dp, num-4),
                5*maxProduct(dp, num-5),
                6*maxProduct(dp, num-6),
                7*maxProduct(dp, num-7),
                8*maxProduct(dp, num-8),
                9*maxProduct(dp, num-9)
            });
        }
    }
    int integerBreak(int n) {
        int dp[59];
        memset(dp, -1, sizeof(dp));
        dp[1]=1, dp[2]=1, dp[3]=2, dp[4]=4, dp[5]=6, dp[6]=9, dp[7]=12, dp[8]=18, dp[9]=27;
        return maxProduct(dp, n);
    }
};

/*
DP Top Down
*/

class Solution {
public:
    vector<int> memo;
    
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        memo = vector(n + 1, 0);
        return dp(n);
    }
    
    int dp(int num) {
        if (num <= 3) {
            return num;
        }
        
        if (memo[num] != 0) {
            return memo[num];
        }
        
        int ans = num;
        for (int i = 2; i < num; i++) {
            ans = max(ans, i * dp(num - i));
        }
        
        memo[num] = ans;
        return ans;
    }
};

/*
DP Bottom up
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        vector<int> dp(n + 1, 0);

        // Set base cases
        for (int i = 1; i <= 3; i++) {
            dp[i] = i;
        }
        
        for (int num = 4; num <= n; num++) {
            int ans = num;
            for (int i = 2; i < num; i++) {
                ans = max(ans, i * dp[num - i]);
            }
            
            dp[num] = ans;
        }
        
        return dp[n];
    }
};

/*
O(n) solution
*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        int ans = 1;
        while (n > 4) {
            ans *= 3;
            n -= 3;
        }
        
        return ans * n;
    }
};
/*
O(log(n)) solution
*/

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        if (n % 3 == 0) {
            return pow(3, n / 3);
        }
        
        if (n % 3 == 1) {
            return pow(3, n / 3 - 1) * 4;
        }
        
        return pow(3, n / 3) * 2;
    }
};