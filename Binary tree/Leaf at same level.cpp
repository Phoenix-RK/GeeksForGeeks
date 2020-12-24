//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1#

Given a Binary Tree, check if all leaves are at same level or not.

Example 1:

Input: 
            1
          /   \
         2     3

Output: 1

Explanation: 
Leaves 2 and 3 are at same level.

Example 2:

Input:
            10
          /    \
        20      30
       /  \        
     10    15

Output: 0

Explanation:
Leaves 10, 15 and 30 are not at same level.

Your Task: 
You dont need to read input or print anything. Complete the function check() which takes root node as input parameter and returns true/false depending on whether all the leaf nodes are at the same level or not.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)
 

Constraints:
1 ≤ N ≤ 10^3

*/



/*You are required to complete this method*/
bool check_leaf(Node* n1,int &h,int d)
{
    if(!n1)
        return true;
    
    if(!n1->left && !n1->right)
    {
        if(h==0)
            h=d;
        
        return h==d;
    }
    
    return check_leaf(n1->left,h,d+1)&&check_leaf(n1->right,h,d+1);
}
bool check(Node *root)
{
    //Your code here
    int h=0,d=0;
    
    return check_leaf(root->left,h,d+1)&&check_leaf(root->right,h,d+1);
}
