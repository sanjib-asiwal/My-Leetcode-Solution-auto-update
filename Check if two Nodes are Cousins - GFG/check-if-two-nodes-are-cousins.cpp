//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

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
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
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

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false

void findcousin(Node* root,int &a,int &b,int level,Node* &nodeAparent,Node* &nodeBparent,int &level1,int &level2){
    if(!root)
    return;
    if(root->left){
        if(root->left->data==a){
            nodeAparent=root;
            level1=level+1;
        }
        if(root->left->data==b){
            nodeBparent=root;
            level2=level+1;
        }
    }
    if(root->right){
        if(root->right->data==a){
            nodeAparent=root;
            level1=level+1;
        }
        if(root->right->data==b){
            nodeBparent=root;
            level2=level+1;
        }
    }

    findcousin(root->left,a,b,level+1,nodeAparent,nodeBparent,level1,level2);
    findcousin(root->right,a,b,level+1,nodeAparent,nodeBparent,level1,level2);
}
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   bool ans=false;
   Node * nodeAparent=NULL,*nodeBparent=NULL;
   int level1=0,level2=0;
    findcousin(root,a,b,1,nodeAparent,nodeBparent,level1,level2);
    
    if(level1==level2&&nodeAparent!=nodeBparent){
        ans=true;
    }
    return ans;
}



