#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node{
        int start;
        int end;
        int profit;
        bool operator < (Node const& a){
            if(start == a.start){
                if(end<a.end){
                    return true;
                }
            }
            return start<a.start;
        }
    };
    int myLowerBound(vector<Node>& Nodes, int target){
        int mid, low=0, high=Nodes.size();
        while(low<high){
            mid = low+(high-low)/2;
            if(target<=Nodes[mid].start){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(low < Nodes.size() && Nodes[low].start < target) {
            low++;
        }
        return low;
    }
    int maximizeProfit(int idx, int n, vector<Node>& Nodes, vector<int>& dp){
        if(idx==n){
            return 0;
        }
        else if(dp[idx]!=-1){
            return dp[idx];
        }
        else{
            int next_idx = myLowerBound(Nodes, Nodes[idx].end);
            return dp[idx] = max(maximizeProfit(idx+1, n, Nodes, dp), maximizeProfit(next_idx, n, Nodes, dp)+Nodes[idx].profit);
        }
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Node> Nodes;
        vector<int> dp(startTime.size()+1, -1);
        for(int i=0; i<startTime.size(); i++){
            Nodes.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(Nodes.begin(), Nodes.end());
        return maximizeProfit(0, startTime.size(), Nodes, dp);
    }
};