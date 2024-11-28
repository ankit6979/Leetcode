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

/* Recursive */
// class Solution {
// public:
//     void inorderTraversalHelper(TreeNode* root, vector<int>& ans) {
//         if(root == NULL) return;
//         inorderTraversalHelper(root->left, ans);
//         ans.push_back(root->val);
//         inorderTraversalHelper(root->right, ans);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         inorderTraversalHelper(root, ans);
//         return ans;
//     }
// };

/* Iterative */
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> inorder;
//         if(!root) return inorder;
//         stack<TreeNode*> s;
//         TreeNode* node = root;

//         while(true) {
//             if(node != NULL) {
//                 s.push(node);
//                 node = node->left;
//             }
//             else {
//                 if(s.empty()) break;
//                 node = s.top(); s.pop();
//                 inorder.push_back(node->val);
//                 node = node->right;
//             }

//         }
//         return inorder;
//     }
// };

/* Morris Traversal */
class Solution {
public:
    TreeNode* findRightMost(TreeNode* parent, TreeNode* node) {
        while(node->right != NULL && node->right != parent) {
            node = node->right;
        }
        return node;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        TreeNode* curr = root;

        while(curr) {
            if(curr->left == NULL) {
                ans.emplace_back(curr->val);
                curr = curr->right;
            }
            else {
                //find rightmost node of left subtree : right_node
                TreeNode* right_node = findRightMost(curr, curr->left);
                if(right_node->right == NULL) {
                    right_node->right = curr;
                    curr = curr->left;
                    // attach thread from rightmost node of left subtree to curr
                }
                else {
                    //move right from current node and delete thread
                    ans.emplace_back(curr->val);
                    right_node->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return ans; 
    }
};