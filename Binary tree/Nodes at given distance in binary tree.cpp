//Phoenix_RK

/*

Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available.

*/


#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

void printkdistanceNodeDown(Node *root, int k);

int printkdistanceNode(Node* root, int target , int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        printkdistanceNode(head, target, k);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
/*  Input:
1 2 3 4 5 N 6
6
4

Its Correct output is:
4 5

And Your Code's output is:
2 3
void printkdistanceNodeDown(Node *root, int k)
{
// Your code here
if(root==NULL)
    return ;
if(k==0)
    cout<<root->data<<" ";
    
    printkdistanceNodeDown(root->left,k-1);
    printkdistanceNodeDown(root->right,k-1);
    
}
/*
 Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
 /*
 int distance(Node *root,int target)
 {
     if(root==NULL)
        return -1;
    
    int dis=-1;
    
    if(root->data==target|| (dis=distance(root->left,target))>=0||(dis=distance(root->right,target))>=0)
        return dis+1;
    return dis;
 }
 
 Node* findNode(Node* root,int target)
 {
     if(root==NULL)
        return NULL;
        
    if(root->data==target)
        return root;
        
    Node* l=findNode(root->left,target);
    if(l==NULL)
        return findNode(root->right,target);
    else
        return l;
 }
 
int printkdistanceNode(Node* root, int target , int k)
{
// Your code here
   Node * t=findNode(root,target);
   if(t==NULL)
     return -1;
    
   int dis= distance(root,target);
   printkdistanceNodeDown(root,k-dis);
   printkdistanceNodeDown(t->left,k-1);
   printkdistanceNodeDown(t->right,k-1);
    return 0;
    

}

 ******************************************************************
*/
 Node* findNode(Node* root,int target)
 {
     if(root==NULL)
        return NULL;
        
    if(root->data==target)
        return root;
        
    Node* l=findNode(root->left,target);
    if(l==NULL)
        return findNode(root->right,target);
    else
        return l;
 }
void fillparent(Node* parent,Node *child,map<Node* ,Node*>&m)
{
    if(child==NULL)
      return;
    
    m[child]=parent;
    fillparent(child,child->left,m);
    fillparent(child,child->right,m);
}

int printkdistanceNode(Node* root, int target , int k)
{
    Node *t=findNode(root,target);

    map<Node*,Node*> m;
    fillparent(NULL,root,m);
    queue<Node*> q;
    q.push(t);
    map<int,int> seen;
    int level=0;
    while(!q.empty())
    {
        int s=q.size();
        while(s>0)
        {
            
            if(level==k)
            {
                Node *f=q.front();
                q.pop();
                cout<<f->data<<" ";
            }
            
            else
            {
                 Node *f=q.front();
                 q.pop();
                 seen[f->data]=1;
                
                
                
                if(f->left && !seen[f->left->data])
                    q.push(f->left);
                    
                if(f->right && !seen[f->right->data])
                    q.push(f->right);
                    
                if(m[f]!=NULL && !seen[m[f]->data])
                    q.push(m[f]);
            }
            s--;
        }
        
        level++;
    }
    
    return 0;
}



