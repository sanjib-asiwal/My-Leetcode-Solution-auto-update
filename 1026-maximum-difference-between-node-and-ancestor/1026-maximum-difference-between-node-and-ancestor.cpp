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
   // int ans=0;
    int helper(TreeNode* root,int pmini,int pmaxi){
        if(!root) return pmaxi-pmini;
        if(root->val>pmaxi){
            pmaxi=root->val;
        }
       else if(root->val<pmini){
            pmini=root->val;
        }
        return max(helper(root->left,pmini,pmaxi),
        helper(root->right,pmini,pmaxi));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
       int ans= helper(root,root->val,root->val);
        return ans;
    }
};