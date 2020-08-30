//Phoneix_RK

/*

https://practice.geeksforgeeks.org/problems/preorder-traversal/1

Given a binary tree, find its preorder traversal.

Example 1:

Input:
        1      
      /          
    4    
  /    \   
4       2
Output: 1 4 4 2 
Example 2:

Input:
       6
     /   \
    3     2
     \   / 
      1 2
Output: 6 3 1 2 2 

Your Task:
You just have to complete the function preorder() which takes the root node of the tree as input and returns an array containing the preorder traversal of the tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 105

*/



/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> res;
  if(root==NULL)
    return res;

stack<Node*> s;
s.push(root);

    while(!s.empty())
    {
        Node* temp=s.top();
        s.pop();
        res.push_back(temp->data);
        
        if(temp->right)
            s.push(temp->right);
        
        if(temp->left)
            s.push(temp->left);
        
    }

return res;
 
}
