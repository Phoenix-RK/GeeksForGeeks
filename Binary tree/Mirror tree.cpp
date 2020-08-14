//Phoenix_RK


/*
Given a Binary Tree, convert it into its mirror.

https://practice.geeksforgeeks.org/problems/mirror-tree/1/

Example 1:

Input:
      1
    /  \
   2    3
Output: 2 1 3
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
3    2          2    3
The inorder of mirror is 2 1 3
Example 2:

Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.







*/


Node* mirror_help(Node* node)
{
     Node* temp=NULL;
     if(node==NULL || (node->right==NULL&&node->left==NULL))
        return node;
    
    else
    {
        temp=node->right;
        node->right=mirror_help(node->left);
        node->left=mirror_help(temp);
    }
   
    
}
void mirror(Node* node) 
{
     // Your Code Here
     
     mirror_help(node);
    
}
