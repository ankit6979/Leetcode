#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int dp[100001];
        priority_queue<int> pq;
        map<int, int> m;
        int max_val;

        dp[0] = nums[0];
        m[dp[0]] = 0;
        pq.push(dp[0]);
        
        for(int i=1; i<nums.size(); i++){
            while(m[pq.top()]<(i-k)){
                pq.pop();
            }
            max_val = max(0, pq.top());
            dp[i] = max_val+nums[i];
            pq.push(dp[i]);
            m[dp[i]] = i;
        }
        max_val = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            max_val = (dp[i]>max_val)?dp[i]:max_val;
        }
        return max_val;
    }
};