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
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp) {
        if(inStart > inEnd || preStart > preEnd) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = mpp[preorder[preStart]];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, mpp);
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);
        return root; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int nodes = inorder.size();
        if(nodes == 0) {
            return NULL;
        }
        unordered_map<int, int> mpp;

        for(int i = 0; i < inorder.size(); ++i) {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = buildTreeHelper(
            preorder, 0, nodes - 1,
            inorder, 0, nodes - 1, mpp
        );

        return root;
    }
};