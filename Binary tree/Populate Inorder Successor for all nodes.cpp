//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#


Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the number of edges respectively. The last line contains the edges of the tree.

Output:
Print the data for both nodes separated by "->" ( without quotes). -1 is printed if there is no successor for the node.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=data of the node<=10^5

Example:
Input:
1
3
10 8 L 8 3 L 10 12 R

Output:
3->8 8->10 10->12 12->-1

*/



/* Set next of p and all descendents of p by traversing them in reverse Inorder */

/*
Node Structure

struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *next;
	
	node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	    next = NULL;
	}
};
*/

void populate(struct node* curr,struct node* &set)
{
    if(curr)
    {
        populate(curr->right,set);
        curr->next=set;
        set=curr;
        populate(curr->left,set);
    }
    
}


void populateNext(struct node* p)
{

// Your code goes here
    struct node *set=NULL;
    
    populate(p,set);    
}
