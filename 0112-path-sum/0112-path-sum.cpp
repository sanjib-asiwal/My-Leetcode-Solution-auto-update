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
    int sum=0;
    bool ans=false;
    void isPath(TreeNode* root, int targetSum){
        if(!root)return ;
        
        if(!root->left&&!root->right){
            sum+=root->val;
            if(sum==targetSum)
            ans=true;
            sum-=root->val;
            return;
        }
        sum+=root->val;
        isPath(root->left,targetSum);
        isPath(root->right,targetSum);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        isPath(root,targetSum);
        return ans;
    }
};