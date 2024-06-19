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
    int str_to_int (string num) {
        int number = 0;
        int place = 0;
        for (int i = num.size() - 1; i >= 0; --i) {
            number += ((num[i] - '0') * pow(10, place));
            ++place;
        }
        return number;
    }
    void traverse_tree(TreeNode* node, string num, int & ans) {
        if (node->left == NULL && node->right == NULL) {
            int curr_num = str_to_int(num);
            ans += curr_num;
            return;
        }
        else if(node->right == NULL) {
            traverse_tree(node->left, num + to_string(node->left->val), ans);
        }
        else if (node->left == NULL) {
            traverse_tree(node->right, num + to_string(node->right->val), ans);
        }
        else {
            traverse_tree(node->left, num + to_string(node->left->val), ans);
            traverse_tree(node->right, num + to_string(node->right->val), ans);
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (root == NULL) {
            return 0;
        }
        string num = to_string(root->val);
        traverse_tree(root, num, ans);
        return ans;
    }
};