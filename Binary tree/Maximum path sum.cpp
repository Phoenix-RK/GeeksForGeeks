//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/maximum-path-sum/1

Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.

*/



 int sum(Node * root,int &max_so_far)
    {
        if(root==NULL)
            return 0;
           
        int ls=sum(root->left,max_so_far);
        int rs=sum(root->right,max_so_far);
        max_so_far=max(max_so_far, ls+rs+root->data);
        return max({0,root->data,ls+ root->data,rs+root->data});
     
    }
    
    int maxPathSum(Node* root) {
    if(root==NULL)
        return 0;
      int max_so_far=INT_MIN;
     int x= sum(root,max_so_far);  
      return max_so_far;
    }
