//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#


Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Examples:

Input : Binary tree:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output : 13

        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Input:
The function takes a single argument as input the reference pointer to the root of the binary tree.
There will be T, test cases and for each test case the function will be called separately.

Output:
For each test case print the required sum on a new line.

Constraints:
1<=T<=103
1<=N<=103

*/



// your task is to complete this function

void sumPath(Node* root,int sum,int len,int &maxsum,int &maxlen)
{
    if(!root)
    {
        if(maxlen < len)
        {
            maxlen = len;
            maxsum = sum;
        }
        else if(maxlen == len && maxsum< sum)
            maxsum = sum;
            
        return;
    }
    
    sumPath(root->left, sum + root->data,len + 1, maxsum, maxlen);
    sumPath(root->right, sum + root->data,len + 1, maxsum, maxlen);
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
    if(root==NULL)
        return 0;
        
    int maxsum=INT_MIN;
    int maxlen = 0;
    
     sumPath(root,0,0,maxsum,maxlen);
     return maxsum;
    
}

