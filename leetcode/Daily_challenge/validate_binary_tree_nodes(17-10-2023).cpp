#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, vector<int>& parent)
    {
        stack<int> s;
        s.push(node);
        visited[node] = true;
        while(!s.empty())
        {
            int curr_node = s.top();
            s.pop();
            int left_node = leftChild[curr_node];
            int right_node = rightChild[curr_node];
            if(left_node != -1){
                if(!visited[left_node]){
                    visited[left_node] = true;
                    parent[left_node] = curr_node;
                    s.push(left_node);
                }
                else{
                    if(parent[left_node] == -1){
                        parent[left_node] = curr_node;
                    }
                    else if(parent[left_node] != curr_node){
                        return false;
                    }
                }
            }
            if(right_node != -1){
                if(!visited[right_node]){
                    visited[right_node] = true;
                    parent[right_node] = curr_node;
                    s.push(right_node);
                }
                else{
                    if(parent[right_node] == -1){
                        parent[right_node] = curr_node;
                    }
                    else if(parent[right_node] != curr_node){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent;
        vector<bool> visited;
        parent.reserve(n);
        visited.reserve(n);
        for(int i=0; i<n; i++){
            parent.push_back(-1);
            visited.push_back(false);
        }
        for(int i=0; i<n; i++){
            if(!dfs(i, leftChild, rightChild, visited, parent)){
                return false;
            }
        }
        int parent_cnt=0, root;
        for(int i=0; i<n; i++){
            if(parent[i]==-1){
                root = i;
                parent_cnt++;
            }
        }
        if(parent_cnt != 1){
            return false;
        }
        for(int i=0; i<n; i++){
            parent[i]=-1;
            visited[i] = false;
        }
        dfs(root, leftChild, rightChild, visited, parent);
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};