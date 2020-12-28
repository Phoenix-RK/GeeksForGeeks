//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1


Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

 

Example 1:

Input:
N = 8
in[] = 4 8 2 5 1 6 3 7
post[] =8 4 5 2 6 7 3 1
Output: 1 2 4 8 5 3 6 7
Explanation: For the given postorder and
inorder traversal of tree the  resultant
binary tree will be
           1
       /      \
     2         3
   /  \      /  \
  4    5    6    7
   \
     8
 

Example 2:

Input:
N = 5
in[] = 9 5 2 3 4
post[] = 5 9 3 4 2
Output: 2 9 5 4 3
Explanation:  
the  resultant binary tree will be
           2
        /     \
       9       4
        \     /
         5   3
 

Your Task:
You do not need to read input or print anything. Complete the function buildTree() which takes the inorder, postorder traversals and the number of nodes in the tree as input parameters and returns the root node of the newly constructed Binary Tree.
The generated output contains the preorder traversal of the constructed tree.

 

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 103
1 <= in[i], post[i] <= 103



*/



int search(int in[],int start,int end,int data)
{
    for(int i=start;i<=end;i++)
    {
        if(in[i]==data)
            return i;
    }
    //return -1;
}

Node*construct(int in[],int post[],int &ind,int inStart,int inEnd)
{
    if(inStart>inEnd)
        return NULL;
    int data = post[ind];    
    Node* temp=new Node(post[ind--]);

    if(inStart==inEnd)
        return temp;

    int inorder_ind = search(in,inStart,inEnd,data);

    temp->right= construct(in,post,ind,inorder_ind+1,inEnd);
    temp->left=construct(in,post,ind,inStart,inorder_ind-1);
    
}

Node* buildTree(int in[],int post[], int n)
{
//add code here.
    int ind=n-1;
    return construct(in,post,ind,0,n-1);
}

