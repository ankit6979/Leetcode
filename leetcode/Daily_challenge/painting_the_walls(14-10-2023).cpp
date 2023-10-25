#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
    int dp[501][2500];
    int zero = 500;

public:
    ll minCost(int start, int end, int time_paid, int time_free, vector<int> &cost, vector<int> &time)
    {
        if (start > end)
        {
            return time_paid >= time_free ? 0 : INT_MAX;
        }
        else if (dp[start][zero + time_paid - time_free] != -1)
        {
            return dp[start][zero + time_paid - time_free];
        }
        /*
        As if difference is gr than 500 then only free painter can do all the other works
        */
        else if (time_paid - time_free > 500)
        {
            return dp[start][zero + time_paid - time_free] = minCost(start + 1, end, time_paid, time_free + 1, cost, time);
        }
        else
        {
            ll free_cost = minCost(start + 1, end, time_paid, time_free + 1, cost, time);
            ll paid_cost = minCost(start + 1, end, time_paid + time[start], time_free, cost, time) + cost[start];
            return dp[start][zero + time_paid - time_free] = min(free_cost, paid_cost);
        }
    }
    ll paintWalls(vector<int> &cost, vector<int> &time)
    {
        memset(dp, -1, sizeof(dp));
        return minCost(0, cost.size() - 1, 0, 0, cost, time);
    }
};