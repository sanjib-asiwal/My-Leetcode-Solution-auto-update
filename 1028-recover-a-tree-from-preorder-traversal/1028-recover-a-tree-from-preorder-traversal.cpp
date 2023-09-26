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
    int id=0;
    unordered_set<char> st={'0','1','2','3','4','5','6','7','8','9'};
    TreeNode* construct(string s,int depth){
        if(id==s.size()) return NULL;
        int cd=0;
        string temp;
        int idx=id;
        while(idx<s.size() && s[idx]=='-'){
            cd++;
            idx++;
        }
        if(cd!=depth) return NULL;
        while(idx<s.size() && st.find(s[idx]) != st.end()){
            temp+=s[idx];
            idx++;
        }
        id=idx;
        TreeNode* root=new TreeNode(stoi(temp));
        root->left=construct(s,depth+1);
        root->right=construct(s,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return construct(traversal,0);
    }
};