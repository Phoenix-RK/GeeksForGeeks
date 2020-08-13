//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present. 

Note: C is the position of the node to which the last node is connected. If it is 0 then no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
C = 2
Output: 1
Explanation: In the first test case
N = 3.The linked list with nodes
N = 3 is given. Here, x = 2 which
means last node is connected with xth
node of linked list. Therefore, there
exists a loop. 

Example 2:
Input:
N = 4
value[] = {1,8,3,4}
C = 0
Output: 1
Explanation: N = 4 and x = 0, which
means lastNode->next = NULL, thus
the Linked list does not contains
any loop.

*********************************************
1)Detect if the linked list has loop
2)Find the starting point of loop
3)Place one pointer at the starting point of slide and move another pointer till the node before the starting node of the loop.
4)Make the next of the second pointer to point to NULL


**********************************************
Best explanation of Floyd algorithm
https://www.youtube.com/watch?v=LUm2ABqAs1w

*/


// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    
    Node* slow=head,*fast=head;
    int flag=0;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        
        if(slow==fast)
        {
            flag=1;
            break;
        }
    }
    
    if(flag==0)
    return;
    
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    
    while(slow->next!=fast)
    {
        slow=slow->next;
    }
    slow->next=NULL;
    return;
}
