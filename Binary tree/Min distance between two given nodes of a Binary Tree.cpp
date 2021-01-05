//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

Given a binary tree and two node values your task is to find the minimum distance between them.



1.Find Lowest common ancestor
2.find dist between both the target node and lca
3.add them
*/


#include <bits/stdc++.h>

using namespace std;

// Tree Node
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
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int findDist(Node *, int, int);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        cout << findDist(root, n1, n2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
   
Node* findNode(Node* root,int x)
{
    if(!root || root->data == x)
        return root;
    Node* l=findNode(root->left,x);
    return l ? l :findNode(root->right,x);
}

Node* findLca(Node* root,int a,int b)
{
    if(!root || root->data==a|| root->data==b)
        return root;
        
    Node* l=findLca(root->left,a,b);
    Node* r=findLca(root->right,a,b);
    
    if(l && r)
        return root;
    return l?l:r;
}
   
int distance(Node* root,int x)
{
    if(!root)
        return -1;
    int dist=-1;
    if(root->data==x || (dist=distance(root->left,x))>=0 || (dist=distance(root->right,x))>=0)
        return dist+1;
    
    return dist;
    
    
    
}
int findDist(Node* root, int a, int b) {
    // Your code here
    
    Node* lca=findLca(root,a,b);
    return distance(lca,a)+distance(lca,b);
}
