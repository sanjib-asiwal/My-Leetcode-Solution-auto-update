/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> path1,path2;
    vector<TreeNode*> temp;
    void CommonAncestor(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root) return;
        temp.push_back(root);
        if(root->val==p->val){
            for(int i=0;i<temp.size();i++){
                path1.push_back(temp[i]);
            }
        }
        if(root->val==q->val){
            for(int i=0;i<temp.size();i++){
                path2.push_back(temp[i]);
            }
        }
        CommonAncestor(root->left,p,q);
        CommonAncestor(root->right,p,q);
        temp.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        CommonAncestor(root,p,q);
        int i=0;
        while(i<path1.size() && i<path2.size()){
            if(path1[i] != path2[i]) break;
            i++;
        }
        return path1[i-1];
    }
};