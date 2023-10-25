#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1002];
    int minCost(int start, int end, vector<int> &cost)
    {
        if (start >= end)
        {
            return 0;
        }
        else if (dp[start] != -1)
        {
            return dp[start];
        }
        else
        {
            return dp[start] = cost[start] + min(
                minCost(start + 1, end, cost),
                minCost(start + 2, end, cost)
            );
        }
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return min(
            minCost(0, cost.size(), cost),
            minCost(1, cost.size(), cost));
    }
};
