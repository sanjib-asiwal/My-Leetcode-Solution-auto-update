/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)   return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            while(qsize--) {
                Node* root = q.front();
                q.pop();
                if(qsize!=0)
                 root->next=q.front();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);  
            }
        }
        return root;   
    }
};