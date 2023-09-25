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
    long long total_sum=0,ans=0;
    int subtreesum(TreeNode *root){
        if(!root) return 0;
        long long sum=root->val+ subtreesum(root->left)+ subtreesum(root->right);
        ans=max(ans,(total_sum-sum)*sum);
        return sum;
    }
    
    int maxProduct(TreeNode* root) {
        total_sum=subtreesum(root);
        subtreesum(root);
        return ans%int(1e9+7);
    }
};