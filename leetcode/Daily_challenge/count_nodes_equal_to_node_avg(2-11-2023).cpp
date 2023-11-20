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
/*
    Optimized solution
*/
class Solution {
public:
    struct sumNum {
        int node_sum, elem_cnt;
    };
    sumNum dfs(TreeNode* node, int& subtree_cnt){
        if(node == NULL){
            return {0, 0};
        }
        sumNum left = dfs(node->left, subtree_cnt);
        sumNum right = dfs(node->right, subtree_cnt);
        int s = node->val+left.node_sum+right.node_sum;
        int c = left.elem_cnt+right.elem_cnt+1;
        if(s/c == node->val){
            subtree_cnt++;
        }
        return {s, c};
    }
    int averageOfSubtree(TreeNode* root) {
        int subtree_cnt=0;
        dfs(root, subtree_cnt);
        return subtree_cnt;
    }
};

/*
    1st solution
*/
class Solution {
public:
    int subtree_cnt=0;
    struct sumNum {
        int node_sum, elem_cnt;
    };
    sumNum dfs(TreeNode* node){
        if(node->left == NULL && node->right == NULL){
            int s = node->val;
            int c = 1;
            if(s/c == node->val){
                subtree_cnt++;
            }
            return {s, c};
        }
        else if(node->left == NULL){
            sumNum right = dfs(node->right);
            int s = node->val+right.node_sum;
            int c = ++right.elem_cnt;
            if(s/c == node->val){
                subtree_cnt++;
            }
            return {s, c};
        }
        else if(node->right == NULL){
            sumNum left = dfs(node->left);
            int s = node->val+left.node_sum;
            int c = ++left.elem_cnt;
            if(s/c == node->val){
                subtree_cnt++;
            }
            return {s, c};
        }
        else{
            sumNum left = dfs(node->left);
            sumNum right = dfs(node->right);
            int s = node->val+left.node_sum+right.node_sum;
            int c = left.elem_cnt+right.elem_cnt+1;
            if(s/c == node->val){
                subtree_cnt++;
            }
            return {s, c};
        }
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return subtree_cnt;
    }
};