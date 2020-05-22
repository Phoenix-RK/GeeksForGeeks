//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/k-distance-from-root/1

Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

*/



/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// function should print the nodes at k distance from root


void printKdistance(struct Node *root, int k)
{
  // Your code here
    if(root==NULL)
        return;
  
    if(k==0)
        cout<<root->data<<" ";
    
    printKdistance(root->left,k-1);
    printKdistance(root->right,k-1);
    

}
