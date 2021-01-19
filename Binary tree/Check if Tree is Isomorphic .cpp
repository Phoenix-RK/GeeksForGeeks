//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#

Given two Binary Trees. Check whether they are Isomorphic or not.

Example 1:

Input:
 T1    1     T2:   1
     /   \        /  \
    2     3      3    2
   /            /
  4            4
Output: No

Example 2:

Input:
T1    1     T2:    1
    /  \         /   \
   2    3       3     2
  /                    \
  4                     4
Output: Yes
Your Task:
You don't need to read input or print anything. Your task is to complete the function isIsomorphic() that takes the root nodes of both the Binary Trees as its input and returns True if the two trees are isomorphic. Else, it returns False. (The driver code will print Yes if th returned values is true, otherwise false.)

Note: 
Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.
For example, following two trees are isomorphic with following sub-trees flipped: 2 and 3, NULL and 6, 7 and 8.
ISomorphicTrees

Expected Time Complexity: O(min(M,N)) where M and N are the sizes of the two trees.
Expected Auxiliary Space: O(min(H1,H2)) where H1 and H2 are the heights of the two trees.

Constraints:
1<=Number of nodes<=105





*/




// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2) 
        return false;
    if(root1->data!=root2->data)
        return false;
    return   ((isIsomorphic(root1->left,root2->left)&&isIsomorphic(root1->right,root2->right)) ||(isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left)));
    
}
