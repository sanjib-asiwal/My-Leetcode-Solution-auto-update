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
unordered_map<int,int> mp;
TreeNode* build(vector<int>& Inorder, vector<int>& Postorder,int i1, int j1, int i2, int j2){
if(i1>j1) return NULL;
TreeNode* root = new TreeNode(Postorder[j1], NULL, NULL);

  int i=mp[Postorder[j1]];

//  for(i=i2; i<=j2; i++){
// if(Inorder[i]==Preorder[i1])
//     break;
// }
    
root->left = build(Inorder,Postorder,i1, i1+i-i2-1, i2, i-1);
root->right = build(Inorder,Postorder,i1+i-i2, j1-1, i+1, j2);
return root;

}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
       return  build(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};