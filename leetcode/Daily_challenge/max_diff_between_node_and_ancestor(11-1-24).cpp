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
    struct Vals{
        int min_val;
        int max_val;
    };
    Vals maximizeDiff(TreeNode* node, int& ans){
        if(node->left== NULL && node->right==NULL){
            return {node->val, node->val};
        }
        else if(node->left == NULL){
            Vals right_val = maximizeDiff(node->right, ans);
            int right_min = right_val.min_val;
            int right_max = right_val.max_val;
            ans = max({ans, abs(node->val-right_min), abs(node->val-right_max)});
            return {min(node->val, right_min), max(node->val, right_max)};
        }
        else if(node->right == NULL){
            Vals left_val = maximizeDiff(node->left, ans);
            int left_min = left_val.min_val;
            int left_max = left_val.max_val;
            ans = max({ans, abs(node->val-left_min), abs(node->val-left_max)});
            return {min(node->val, left_min), max(node->val, left_max)};
        }
        else{
            Vals left_val = maximizeDiff(node->left, ans);
            Vals right_val = maximizeDiff(node->right, ans);
            int right_min = right_val.min_val;
            int right_max = right_val.max_val;
            int left_min = left_val.min_val;
            int left_max = left_val.max_val;
            ans = max({ans, abs(node->val-left_min),abs(node->val-left_max),abs(node->val-right_min),abs(node->val-right_max)});
            return {min({node->val, left_min, right_min}), max({node->val, left_max, right_max})};
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        maximizeDiff(root, ans);
        return ans;
    }
};