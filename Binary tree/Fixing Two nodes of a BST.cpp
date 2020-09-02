//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST by swapping them back. Do not change the structure of the tree.

Note: It is guaranteed than the given input will form BST, except for 2 nodes that will be wrong.


*/


/*Complete the function
Node is as follows:

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

*/

void findDefect(Node *root, Node *&prev, Node *&first, Node *&second)
{
    if(root == NULL)
    {
        return;
    }
    
    findDefect(root->left, prev, first, second);
    
    if(prev != NULL && root->data < prev->data)
    {
        if(first == NULL)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    
    findDefect(root->right, prev, first, second);

}

struct Node *correctBST(struct Node *root)
{
    Node *prev = NULL, *first = NULL, *second = NULL;
    
    findDefect(root, prev, first, second);
    
    swap(first->data, second->data);
    
    return root;
}


