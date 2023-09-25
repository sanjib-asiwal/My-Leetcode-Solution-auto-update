/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialization(TreeNode* root,string & s){
        if(!root){
            s+="N ";
            return;
        }
        s+=to_string(root->val);
        s+=" ";
        serialization(root->left,s);
        serialization(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        serialization(root,s);
        return s;
    }
    
  TreeNode*  deserialization(int& i,string & data){
     
        if(data[i] == 'N'){
            i+=2;
            return NULL;
        }
          string tmp = "";
          while(data[i] != ' ') tmp += data[i++];
          TreeNode *root=new TreeNode(stoi(tmp));
          i++;
          root->left=deserialization(i,data);
          root->right=deserialization(i,data);
          return root;
     
     
  }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root=NULL;
        int i=0;
        return deserialization(i,data);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));