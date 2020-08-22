//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/


Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \  /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
Your Task:
You don't have to read any input. Just complete the function getMaxWidth() that takes node as parameter and returns the maximum width. The printing is done by the driver code.



*/


int height(Node* root)
{
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

int level(Node* root,int i)
{
    if(root==NULL)
        return 0;
        
    if(i==1)
        return 1;
    
    return level(root->left,i-1)+ level(root->right,i-1);
    
}

int getMaxWidth(Node* root)
{
    
   // Your code here
   
   int h=height(root);
   int count=INT_MIN;
   int m=0;
   for(int i=1;i<=h;i++)
   {
       m=level(root,i);
       count=max(m,count);
   }
   return count;
}

