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
    int solve(TreeNode* root, long long currSum, int targetSum, unordered_map<long long,int>&mp){
        if(root == NULL) return 0;      
        
        currSum += root->val;
        
        int res = 0;
        if(mp.find(currSum-targetSum) != mp.end()) res = mp[currSum-targetSum];
        
        mp[currSum]++;
        res += solve(root->left, currSum, targetSum, mp);
        res += solve(root->right, currSum, targetSum, mp);
        mp[currSum]--;
        
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int>mp;
        mp[0]++;
        return solve(root, 0, targetSum, mp);
    }
};