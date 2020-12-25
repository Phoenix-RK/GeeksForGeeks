//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST. 

Example 1:

Input:
     2
   /   \
  1     3
K = 4
Output: 1 2 3 4
Explanation: After inserting the node 4
Inorder traversal will be 1 2 3 4.
Example 2:

Input:
        2
      /   \
     1     3
             \
              6
K = 4
Output: 1 2 3 4 6
Explanation: After inserting the node 4
Inorder traversal of the above tree
will be 1 2 3 4 6.

Your Task:
You don't need to read input or print anything. Your task is to complete the function insert() which takes the root of the BST and Key K as input parameters and returns the root of the modified BST after inserting K. 
Note: The generated output contains the inorder traversal of the modified tree.


Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Number of nodes <= 105
1 <= K <= 106
*/



// The function returns the root of the BST (currently rooted at 'root') 
// after inserting a new Node with value 'Key' into it. 
Node* insert(Node* root, int Key)
{
    // Your code here
    if(!root)
    {
        Node* temp=new Node(Key);
        return temp;
    }
    
    
    if(root->data>Key)
        root->left=insert(root->left,Key);
    
    else if(root->data<Key)
        root->right=insert(root->right,Key);
  
    else
        return root;
}


