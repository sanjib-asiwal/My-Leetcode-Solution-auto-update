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
    vector<vector<int>>ans;
    int sum=0;
    void isPath(TreeNode* root, int targetSum,vector<int>&temp){
        
        if(!root)return ;
        
        if(!root->left&&!root->right){
            sum+=root->val;
            temp.push_back(root->val);
            if(sum==targetSum)
            ans.push_back(temp);
            sum-=root->val;
            temp.pop_back();
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);
        isPath(root->left,targetSum,temp);
        isPath(root->right,targetSum,temp);
        temp.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return ans;
        vector<int>temp;
        isPath(root,targetSum,temp);
        return ans;
    }
};