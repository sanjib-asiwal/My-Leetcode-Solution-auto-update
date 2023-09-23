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
    void traverse(TreeNode* root, vector<int>& pre){
        if(!root) {
            pre.push_back(1e7);
            return;
        }
        pre.push_back(root->val);
        traverse(root->left,pre);
        traverse(root->right,pre);
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> pre1,pre2;
        traverse(root,pre1);
        traverse(subRoot,pre2);
        if(pre1.size()<pre2.size()) return false;
        for(int i=0;i<=pre1.size()-pre2.size();i++){
            int count=0;
            for(int j=i;j<i+pre2.size();j++){
                if(pre1[j]==pre2[j-i])
                    count++;
            }
            if(count==pre2.size()) return true;
        }
        return false;
    }
};