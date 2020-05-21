//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/construct-tree-from-preorder-traversal/1


Given an array pre[] that represents Preorder traversal of a binary tree. One more array preLN[] is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.

it is a special binary tree where every node has either 0 or 2 children​

*/


#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

void printInorder (struct Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder (node->right);
}

Node* constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* root = NULL;
        int n;
        cin>>n;
        int pre[n];
        char preLN[n];
        for(int i=0; i<n; i++)cin>>pre[i];
        for(int i=0; i<n; i++)cin>>preLN[i];
        root = constructTree (n, pre, preLN);
        printInorder(root);
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed


struct Node *construct(int n,int pre[],char preLN[],int *ind)
{
(*ind)++;
  if(n<=(*ind))
  return NULL;
  

    Node *root=new Node(pre[*ind]);
    if(preLN[*ind]=='L')
    {
        root->left=NULL;
        root->right=NULL;
        return root;
    }

       
    root->left=construct(n,pre,preLN,ind);
    root->right=construct(n,pre,preLN,ind);
    return root;
}
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
  int ind=-1;
  return construct(n,pre,preLN,&ind);
  
}


