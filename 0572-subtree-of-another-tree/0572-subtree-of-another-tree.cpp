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
    bool areSame(TreeNode* r1, TreeNode* r2){
        if(!r1&&!r2) return true;
        if(!r1 || !r2) return false;
        return r1->val==r2->val &&
        areSame(r1->left,r2->left) &&
        areSame(r1->right,r2->right);
    }
    
   void traverse(TreeNode* r1, TreeNode* r2,bool &ans){
        if(areSame(r1,r2)){
            ans=true;
            return;
        }
        if(!r1) return;
         traverse(r1->left,r2,ans);
         traverse(r1->right,r2,ans);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        traverse(root,subRoot,ans);
        return ans;
        
    }
};