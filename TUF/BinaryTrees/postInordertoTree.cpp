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
    TreeNode* buildTreeHelper(vector<int>& postorder, int poStart, int poEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp) {
        if(inStart > inEnd || poStart > poEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[poStart]);
        int inRoot = mpp[root->val];
        int numsRight = inEnd - inRoot;

        root->right = buildTreeHelper(postorder, poStart + 1, poStart + numsRight, inorder, inRoot + 1, inEnd, mpp);
        root->left = buildTreeHelper(postorder, poStart + numsRight + 1, poEnd, inorder, inStart, inRoot - 1, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;

        unordered_map<int, int> mpp;

        reverse(postorder.begin(), postorder.end());
        for(int i = 0; i < inorder.size(); ++i) {
            mpp[inorder[i]] = i;
        }

        return buildTreeHelper(
            postorder, 0, postorder.size() - 1, 
            inorder, 0, inorder.size() - 1,
            mpp
        );
    }
};