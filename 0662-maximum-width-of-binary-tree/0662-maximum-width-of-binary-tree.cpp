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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int highest,low ,high;
             highest=q.front().second;
             
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                int newlow=q.front().second-highest;
                q.pop();
                if(i==0) low=newlow;
                if(i==size-1) high=newlow;
                
             
                if(node->left)
                    q.push({node->left,newlow*(long long)2+1});

                if(node->right)
                    q.push({node->right,newlow*(long long)2+2});
            }
            ans=max(ans,high-low+1);
        }
        return ans;
    }
};