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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> que;        
        que.push(root);
        int level = 0;
        bool rowAdded = false;
        while(!que.empty()) {
            int n = que.size();
            level++;
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                TreeNode* tempL = curr->left;
                TreeNode* tempR = curr->right;
                if(level == d-1) {
                    curr->left  = new TreeNode(v);
                    curr->right = new TreeNode(v);
                    curr->left->left   = tempL;
                    curr->right->right = tempR;
                    rowAdded = true;
                }
                if(tempL)
                    que.push(tempL);
                if(tempR)
                    que.push(tempR);
            }
            if(rowAdded)
                break;
        }       
        return root;
    }
};