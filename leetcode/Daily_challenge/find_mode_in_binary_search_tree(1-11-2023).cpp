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
    vector<int> ans;
    int maxStreak=0, currStreak=0, currNum=0;
    void dfs(TreeNode* node){
        if(node == nullptr){
            return;
        }
        dfs(node->left);
        int num = node->val;
        if(num == currNum){
            currStreak++;
        }
        else{
            currStreak=1;
            currNum = num;
        }
        if(currStreak>maxStreak){
            ans = {};
            maxStreak = currStreak;
        }
        if(currStreak==maxStreak){
            ans.push_back(num);
        }
        dfs(node->right);
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};