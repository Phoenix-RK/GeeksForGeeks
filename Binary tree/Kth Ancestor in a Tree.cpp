//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1#

Given a binary tree of size  N, a node and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.


Example 1:



Input:
     K = 2
     Node = 4
Output: 1
Explanation:
Since, K is 2 and node is 4, so we
first need to locate the node and
look k times its ancestors.
Here in this Case node 4 has 1 as his
2nd Ancestor aka the Root of the tree.
 

Example 2:

Input:
k=1 
node=3
      1
    /   \
    2     3

Output:
1
Explanation:
K=1 and node=3 ,Kth ancestor of node 3 is 1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1<=N<=104
1<= K <= 100




*/



bool helper(Node* root,int& k,int node, int& ans)
{
    if(!root)
        return false;
        
    if(root->data==node)
        return true;
        
    if(helper(root->left,k,node,ans) || helper(root->right,k,node,ans))
    {
        k=k-1;
        if(k==0)
            ans=root->data;
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    
    int ans=-1;
    if(!root)
        return ans;
        
    helper(root,k,node,ans);
    
    return ans;
}


