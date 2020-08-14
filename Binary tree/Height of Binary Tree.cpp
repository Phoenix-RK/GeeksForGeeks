//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1


Given a binary tree, find its height.

​​Example 1:

Input:
      1
    /  \
   2    3
Output: 2
Example 2:

Input:
  2
   \
    1
   /
 3
Output: 3   

*/


int height(Node* root)
{
   // Your code here
   if(root==NULL)
    return 0;
    
return 1+max(height(root->left),height(root->right));
}


