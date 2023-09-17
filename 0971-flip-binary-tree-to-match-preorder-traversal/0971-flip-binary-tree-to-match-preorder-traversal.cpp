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
    int i;
    vector<int> res;
    vector<int> v;
    
    bool dfs(TreeNode* node) {
        if (!node) return true;
        if (node->val != v[i++]) return false;

        if (node->left && node->left->val != v[i]) {
            res.push_back(node->val);
            return dfs(node->right) && dfs(node->left);
        }
        else {
            return dfs(node->left) && dfs(node->right);
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        i = 0;
        v = voyage;
        return  dfs(root) ? res : vector<int>{-1};
    }

};