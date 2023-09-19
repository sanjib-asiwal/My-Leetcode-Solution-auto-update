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
    //unordered_map<int,vector<TreeNode*>> trees;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0){
            return {};
        }
        if(n==1){
            TreeNode *root=new TreeNode(0);
            return {root};
        }
       // if(trees.find(n)!=trees.end()) return trees[n];
        vector<TreeNode*> result;
        for(int i=1;i<n;i+=2){
                   vector<TreeNode*> lst = allPossibleFBT(i);
                    vector<TreeNode*> rst = allPossibleFBT(n-1-i);
                    for(auto &j: lst){
                        for(auto &k: rst){
                            TreeNode* root = new TreeNode(0);
                            root->left = j;
                            root->right = k;
                            result.push_back(root);    
                        }
                    }
        } 
      //  return trees[n]=result;
        return result;
    }      
    
};