#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, int> nodes;
    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        nodes[root] = 1;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                nodes[node->left] = nodes[node]+1;
            }
            if(node->right){
                q.push(node->right);
                nodes[node->right] = nodes[node]+1;
            }
        }
    }
    vector<int> largestValues(TreeNode* root) {
        map<int, int> res;
        vector<int> ans;
        if(!root){
            return ans;
        }
        bfs(root);
        map<TreeNode*, int>:: iterator it=nodes.begin();
        while(it != nodes.end()){
            if(res.find(it->second) == res.end()){
                res[it->second] = it->first->val;
            }
            else if(it->first->val>res[it->second]){
                res[it->second] = it->first->val;
            }
            it++;
        }
        map<int, int>:: iterator itr =res.begin();
        while(itr != res.end()){
            ans.push_back(itr->second);
            itr++;
        }
        return ans;
    }
};