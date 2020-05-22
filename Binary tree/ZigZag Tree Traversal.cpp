//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

Given a binary tree of size N, your task is to complete the function zigZagTraversal(), that prints the nodes of binary tree in ZigZag manner.


*/


int height(Node* root)
{
	if(root==NULL)
	    return 0;
	return max(height(root->left),height(root->right))+1;
}

void print(Node* root,int h,bool flag)
{
	if(root==NULL)
	    return;

	if(h==1)
	{
	    cout<<root->data<<" ";
	}

	if(!flag)
	{
	    print(root->left,h-1,flag);
	    print(root->right,h-1,flag);
	}
	else if(flag)
	{
	     print(root->right,h-1,flag);
	     print(root->left,h-1,flag);
	}


}
void zigZagTraversal(Node* root)
{
	// Code here
	
        int h=height(root);
        bool flag=false;
        for(int i=1;i<=h;i++)
        {
            print(root,i,flag);
            flag=!flag;
        }
}
