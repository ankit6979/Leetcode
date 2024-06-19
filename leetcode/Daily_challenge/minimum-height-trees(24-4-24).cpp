#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> dfs (vector<vector<int>>& graph, int start, vector<int>& visited, vector<int>& path, int pass) {
        if (pass == 2) {
            path.push_back(start);
        }
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        int max_depth = -1;
        int distant_node;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < graph[curr].size(); ++i) {
                if (visited[graph[curr][i]] == 0) {
                    q.push(graph[curr][i]);
                    visited[graph[curr][i]] = visited[curr] + 1;
                    if (visited[graph[curr][i]] > max_depth) {
                        max_depth = visited[graph[curr][i]];
                        distant_node = graph[curr][i];
                        if (pass == 2) {
                            path.push_back(distant_node);
                        }
                    }
                }
            }
        }
        return make_pair(distant_node, max_depth);
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> graph (n);
        vector<int> visited (n, 0);
        vector<int> path;
        int start_node, end_node;
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        pair<int, int> node = dfs(graph, 0, visited, path, 1);
        start_node = node.first;
        fill (visited.begin(), visited.end(), 0);
        node = dfs(graph, node.first, visited, path, 2);
        end_node = node.first;
        if (node.second % 2 == 1) {
            return {path[path.size()/2]};
        }
        else {
            return {path[(path.size()/2)], path[(path.size()/2) - 1]};
        }
        return {};
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();