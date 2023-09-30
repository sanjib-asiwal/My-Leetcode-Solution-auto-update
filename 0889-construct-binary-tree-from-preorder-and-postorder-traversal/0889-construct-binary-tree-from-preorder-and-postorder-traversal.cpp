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
    TreeNode* dfs(vector<int>& preorder,int pre_start,int pre_end,vector<int>&postorder,int post_start,int post_end) {
        if(pre_start>pre_end) return NULL;
        TreeNode* root=new TreeNode(preorder[pre_start]);
        
        if(pre_start == pre_end) return root;
        
        int post_index=post_start;
        while(postorder[post_index]!= preorder[pre_start+1]) post_index++;
        
        int len=post_index-post_start+1;
        root->left=dfs(preorder,pre_start+1,pre_start+len,postorder,post_start,post_index);
        root->right=dfs(preorder,pre_start+len+1,pre_end,postorder,post_index+1,post_end-1);
        return root;

    }          
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return dfs(preorder,0,preorder.size()-1,postorder,0,preorder.size()-1);
    }
};