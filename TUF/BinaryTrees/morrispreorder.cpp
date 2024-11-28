#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preOrderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        TreeNode* curr = root;

        while(curr) {
            if(curr->left == NULL) {
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* node = curr->left;
                ans.emplace_back(curr->val);
                while(node->right != NULL && node->right != curr) {
                    node = node->right;
                }
                if(node->right == NULL) {
                    node->right = curr;
                    ans.emplace_back(curr->val)
                    curr = curr->left;
                }
                else {
                    node->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans; 
    }
};