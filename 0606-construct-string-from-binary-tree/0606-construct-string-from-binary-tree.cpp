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
    string construct(TreeNode* root){
        if(!root) return "";
        if(!root->left && !root->right) return to_string(root->val) + "";
        
        if(!root->right){
            return to_string(root->val)+ "(" +construct(root->left)  + ")";
            
        }
        return to_string(root->val)+ "(" +construct(root->left) + ")" + "(" + construct(root->right) + ")";
    }
    string tree2str(TreeNode* root) {
        return construct(root);
    }
};