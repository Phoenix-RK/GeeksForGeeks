//Phoenix_RK

/*


Write a function to print Boundary Traversal of a binary tree. Boundary Traversal of a binary tree here means that you have to print boundary nodes of the binary tree Anti-Clockwise starting from the root.
Note: Boundary node means nodes present at the boundary of left subtree and nodes present at the right subtree also including leaf nodes.
For the below tree, the function should print 20 8 4 10 14 25 22 .
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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


void printBoundary(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        printBoundary(root);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends


/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
void leftprint(Node * root)
{
   if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    cout<<root->data<<" ";
    if(root->left)
        leftprint(root->left);
/*		2
	3            5
	    4      6   7
*/
    else if(root->right)
        leftprint(root->right);
    
}

void rightprint(Node * root)
{
     if(root==NULL || (root->left==NULL && root->right==NULL))
        return;
    
    if(root->right)
        rightprint(root->right);
/*		2
	3            5
    4      6       7
*/
    else if(root->left)
        rightprint(root->left);
    cout<<root->data<<" ";
}

void leafprint(Node *root)
{
      if(root==NULL)
        return;
        
    if(root->left)
        leafprint(root->left);

    if(root->right)
        leafprint(root->right);
        
    if(!root->left && !root->right)
        cout<<root->data<<" ";
}

void printBoundary(Node *root)
{
     //Your code here
     if(root)
     {
         cout<<root->data<<" ";
         leftprint(root->left);
         leafprint(root->left);
         leafprint(root->right);
         rightprint(root->right);
     }
}
