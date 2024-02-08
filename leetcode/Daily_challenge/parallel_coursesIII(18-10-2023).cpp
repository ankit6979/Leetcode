#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {
        int max_time = -1;
        vector<int> graph[n+1];
        vector<int> indegree(n+1, 0);
        vector<int> min_time(n, 0);
        for(int i=0; i<relations.size(); i++)
        {
            graph[relations[i][0]].push_back(relations[i][1]);
            indegree[relations[i][1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                min_time[i-1] = time[i-1];
            }
        }
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto neighbour: graph[front])
            {
                indegree[neighbour]--;
                min_time[neighbour-1] = max(min_time[neighbour-1], time[neighbour-1]+min_time[front-1]);
                if(indegree[neighbour]==0)
                {
                    q.push(neighbour);
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(min_time[i]>max_time)
            {
                max_time = min_time[i];
            }
        }
        // cout<<endl;
        return max_time;
    }
};