//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/construct-tree-1/1


Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Example 1:

Input:
N = 4
inorder[] = {1 6 8 7}
preorder[] = {1 6 7 8}
Output: 8 7 6 1
Example 2:

Input:
N = 6
inorder[] = {3 1 4 0 5 2}
preorder[] = {0 1 3 4 2 5}
Output: 3 4 1 5 2 0
Explanation: The tree will look like
       0
    /     \
   1       2
 /   \    /
3    4   5
Your Task:
Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, preorder traversal array, and size of tree n) and returns the root node to the tree constructed. You are not required to print anything and a new line is added automatically (The post order of the returned tree is printed by the driver's code.)

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(N).

Constraints:
1<=Number of Nodes<=1000



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

Node*construct(int in[],int pre[],int &ind,int inStart,int inEnd)
{
    if(inStart>inEnd)
        return NULL;
    int data = pre[ind];    
    Node* temp=new Node(pre[ind++]);
    
    if(inStart==inEnd)
        return temp;
    
    int inorder_ind = search(in,inStart,inEnd,data);
    
    temp->left=construct(in,pre,ind,inStart,inorder_ind-1);
    temp->right= construct(in,pre,ind,inorder_ind+1,inEnd);
    
}

Node* buildTree(int in[],int pre[], int n)
{
//add code here.
    int ind=0;
    return construct(in,pre,ind,0,n-1);
}
