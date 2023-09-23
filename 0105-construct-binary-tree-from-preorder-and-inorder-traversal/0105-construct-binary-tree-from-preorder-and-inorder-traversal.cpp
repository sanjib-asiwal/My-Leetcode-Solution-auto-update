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
TreeNode* build(vector<int>& Preorder, vector<int>& Inorder,int i1, int j1, int i2, int j2){
if(i1)
if(i1>j1) return NULL;
TreeNode* root = new TreeNode(Preorder[i1], NULL, NULL);

 int i;

 for(i=i2; i<=j2; i++){
if(Inorder[i]==Preorder[i1])
    break;
}
root->left = build(Preorder,Inorder,i1+1, i1+i-i2, i2, i-1);
root->right = build(Preorder,Inorder,i1+i-i2+1, j1, i+1, j2);
return root;

}
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return  build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        
    }
};