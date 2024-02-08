#include<bit/stdc++.h>
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
    int bit_toggle(int number, int n) {
        return number ^ ((int)1 << n);
    }

    bool bit_check(int number, int n) {
        return (number >> n) & (int)1;
    }

    int countPalindrome(TreeNode* node, int parity){
        if(node->left==NULL && node->right==NULL){
            parity = bit_toggle(parity, node->val);
            int set_bit_cnt=0;
            for(int i=1; i<=10; i++){
                if(bit_check(parity, i)){
                    set_bit_cnt++;
                }
            }
            if(set_bit_cnt<=1){
                return 1;
            }
            return 0;
        }
        else if(node->left == NULL){
            parity = bit_toggle(parity, node->val);
            return countPalindrome(node->right, parity);
        }
        else if(node->right == NULL){
            parity = bit_toggle(parity, node->val);
            return countPalindrome(node->left, parity);
        }
        else{
            parity = bit_toggle(parity, node->val);
            return countPalindrome(node->left, parity)+countPalindrome(node->right, parity);
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return countPalindrome(root, 0);
    }
};