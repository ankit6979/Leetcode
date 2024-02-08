#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
class Solution {
public:
    int dp[31][1001];
    int findTargetSum(int n, int k, int target){
        if(target < 0){
            return 0;
        }
        else if(n==0){
            if(target == 0){
                return 1;
            }
            return 0;
        }
        else if(dp[n][target] != -1){
            return dp[n][target];
        }
        else{
            int ways = 0;
            for(int i=1; i<=k; i++){
                ways = ((ways%mod)+(findTargetSum(n-1, k, target-i)%mod))%mod;
            }
            return dp[n][target] = ways;
        }
    }
    int numRollsToTarget(int n, int k, int target) {
        int total_ways=0;
        memset(dp, -1, sizeof(dp));
        for(int i=1; i<=k; i++){
            total_ways = ((total_ways%mod)+(findTargetSum(n-1, k, target-i)%mod))%mod;
        }
        return total_ways;
    }
};