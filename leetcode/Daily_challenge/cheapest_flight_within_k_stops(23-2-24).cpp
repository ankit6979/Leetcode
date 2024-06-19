#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[102][102];
    struct Flight{
        int dst;
        int cost;
    };
    int cheapestRoute(vector<vector<Flight>>& flight_graph, int src, int dst, int k){
        if(src==dst){
            return 0;
        }
        else if(k==0){
            return 1e8;
        }
        else if(dp[src][k] != -1){
            return dp[src][k];
        }
        else{
            int min_val=1e8;
            for(int i=0; i<flight_graph[src].size(); i++){
                min_val = min(min_val, cheapestRoute(flight_graph, flight_graph[src][i].dst, dst, k-1)+flight_graph[src][i].cost);
            }
            return dp[src][k] = min_val;
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        memset(dp, -1, sizeof(dp));
        vector<vector<Flight>> flight_graph;
        flight_graph.resize(n+1);
        for(int i=0; i<flights.size(); i++){
            flight_graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        int ans = cheapestRoute(flight_graph, src, dst, k+1);
        if(ans == 1e8){
            return -1;
        }
        return ans;
    }
};