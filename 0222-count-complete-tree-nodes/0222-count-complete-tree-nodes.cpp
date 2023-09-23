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
    pair<bool,int>isPerfect(TreeNode* root){
        int hleft=0;
        TreeNode *tmp=root;
        while(tmp){
            hleft++;
            tmp=tmp->left;
        }
        int hRight=0;
        tmp=root;
        while(tmp){
            hRight++;
            tmp=tmp->right;
        }
        return {hleft==hRight,hleft};
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int cnt=1;
        pair<bool,int>pLeft=isPerfect(root->left);
        pair<bool,int>pRight=isPerfect(root->right);
        if(pLeft.first)
            cnt+=pow(2,pLeft.second)-1;
        else
            cnt+=countNodes(root->left);
        if(pRight.first)
            cnt+=pow(2,pRight.second)-1;
        else
            cnt+=countNodes(root->right);
        return cnt;
    }
};