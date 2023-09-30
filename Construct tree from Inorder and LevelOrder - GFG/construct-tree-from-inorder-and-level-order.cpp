//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/
Node* mybuildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n){
        //base condition if left and right not exists
        if(iStart>iEnd) return NULL;
        Node* root=new Node(levelOrder[0]);
        //base condition leaf node
        if(iStart==iEnd) return root;
        
        //finding root (first node of levelOrder) in inorder and 
        //idx will be index of that root 
        int idx=iStart;
        while(inorder[idx]!=root->key) idx++;
        
        //all left from idx in inorder update in set
        unordered_set<int> set;
        for(int i=iStart;i<idx;i++) set.insert(inorder[i]);
        
        //making new levelorder for left and right call
        //in every call we are passing new level order 
        //and for inorder we are just passing index
        int x=iEnd-iStart+1;
        int lLevel[set.size()] = {0};
        int rLevel[x-set.size()] = {0};
        int li=0,ri=-0;
        //if the curr element in levelorder is in set it means it should be
        //a part of new left levelorder  
        for(int i=1;i<iEnd-iStart+1;i++){
            if(set.find(levelOrder[i])!=set.end())
               lLevel[li++]=levelOrder[i];
            else
                rLevel[ri++]=levelOrder[i];
        }
        
        root->left=mybuildTree(inorder,lLevel,iStart,idx-1,n);
        root->right=mybuildTree(inorder,rLevel,idx+1,iEnd,n);
        return root;
}
Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n)
{
return mybuildTree(inorder,levelOrder,iStart,iEnd,n);
}