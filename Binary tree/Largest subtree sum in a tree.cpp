//Phoenix_RK


/*

https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/

Given a binary tree, task is to find subtree with maximum sum in tree.

Examples:

Input :       1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output : 28
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Input :       1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output : 7
Subtree with largest sum is :  -2
                             /  \ 
                            4    5
Also, entire tree sum is also 7.


*/


class Solution {
public:
    int helper(TreeNode* root,int& freq,map<int,int>& m)
    {
        if(!root)
            return 0;
        
        int l = helper(root->left,freq,m);
        int r = helper(root->right,freq,m);
        int sum=l+r+root->val;
       
        ans = max(ans,sum);
        return sum;
        
    }
    int largestSum(TreeNode* root) {
       
        if(!root)
            return -1;
        int ans=INT_MAX;
        helper(root,ans);
        
     
        return ans;  
    }
};
