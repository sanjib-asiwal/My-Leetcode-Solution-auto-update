//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution {
public:
    int ans;

    int NumberOFTurns(Node* root, int first, int second) {
        ans = 0;
        Node* lca = FindLCA(root, first, second);
        bool left = true;
        
        if (lca->data == first) {
            FindCount(lca->left, left, second);
            FindCount(lca->right, !left, second);
        }
        else if (lca->data == second) {
            FindCount(lca->left, left, first);
            FindCount(lca->right, !left, first);
        }
        else {
            FindCount(lca->left, left, first);
            FindCount(lca->right, !left, first);
            FindCount(lca->left, left, second);
            FindCount(lca->right, !left, second);
            return ans + 1;
        }
        
        return ans;
    }
    
    bool FindCount(Node* node, bool left, int key) {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        
        if (left) {
            if (FindCount(node->left, left, key)) {
                return true;
            }
            if (FindCount(node->right, !left, key)) {
                ans++;
                return true;
            }
        }
        else {
            if (FindCount(node->right, left, key)) {
                return true;
            }
            if (FindCount(node->left, !left, key)) {
                ans++;
                return true;
            }
        }
        return false;
    }
    
     Node* FindLCA(Node* root, int first, int second) {
        if (root == nullptr) return nullptr;
        if (root->data == first || root->data == second) {
            return root;
        }
        
        Node* leftLCA = FindLCA(root->left, first, second);
        Node* rightLCA = FindLCA(root->right, first, second);
        
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }
        else {
            return leftLCA == nullptr ? rightLCA : leftLCA;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends