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
    int getMaxleaveNode(int x, int y) {
    if (y == 0) return 1;
    int ans = getMaxleaveNode(x, y / 2);
    if (y % 2 == 0) return ans * ans;
    else return ans * ans * x;
}

    bool isNullNode(TreeNode *root,int Max_NodesinLastLevel,int mid){
        if(mid>Max_NodesinLastLevel)
        return true;
        int low=1,high=Max_NodesinLastLevel;
        while(high>low){
            int m=(low+high)/2;
            if(mid<=m){
                root=root->left;
                high=m;
            }else{
                root=root->right;
                low=m+1;
            }
        }
        return !root;
    }
    int getHeight(TreeNode *root){
        int ans=0;
        while(root){
            ans++; root=root->left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int ht=getHeight(root);
        int base=2;
        int Max_NodesinLastLevel=getMaxleaveNode(base,ht-1);
        
        int low=1,high=Max_NodesinLastLevel;
        int ans,mid;
        while(low<=high){
            mid=(low+high)/2;
            bool x=isNullNode(root,Max_NodesinLastLevel,mid);
            if(x)
                high=mid-1;
            else{
                if(isNullNode(root,Max_NodesinLastLevel,mid+1)){
                    ans=mid;
                    break;
                }
                else
                    low=mid+1;
            }
        }
        return ans+(Max_NodesinLastLevel-1);
    }
};