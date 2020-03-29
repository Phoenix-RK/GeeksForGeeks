//Phoenix-RK
/* Given a binary tree, print the bottom view from left to right.
A node is included in bottom view if it can be seen when we look at the tree from bottom.

Input:
2
1 3 2
10 20 30 40 60
Output:
3 1 2
40 20 60 30



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


void bottomView(Node *root);

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

        bottomView(root);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; 
*/


void create(Node *root,int hd,int d,map<int,pair<int,int>> &m)
{
    if(root==NULL)
        return ;
    if(m.find(hd)==m.end())
    {
      
        m[hd]=make_pair(d,root->data);
    }
    else
    {
       pair<int,int> p= m[hd];
       if(p.first<=d)
       {
           m[hd].first=d;
           m[hd].second=root->data;
       }
    }
    
     create(root->left,hd-1,d+1,m);
     create(root->right,hd+1,d+1,m);
    
    
    
}

void bottomView(Node* root)
{
    int hd=0,d=0;
    map<int,pair<int,int>> m;
    create(root,hd,d,m);
    
     map<int,pair<int,int>> :: iterator it;
     for(it=m.begin();it!=m.end();++it)
     {
       //  for(int i=0;i<it->second.size();i++)
            cout<<it->second.second<<" ";
     }
    
}
