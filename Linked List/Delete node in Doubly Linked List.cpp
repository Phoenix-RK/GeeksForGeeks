//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Example 1:

Input:
LinkedList = 1 <--> 3 <--> 4 
x = 3
Output: 1 3  
Explanation: After deleting the node at
position 3 (position starts from 1),
the linked list will be now as 1->3.
Example 2:

Input:
LinkedList = 1 <--> 5 <--> 2 <--> 9  
x = 1
Output: 5 2 9
Your Task:
The task is to complete the function deleteNode() which should delete the node at given position and return the head of the linkedlist.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
2 <= size of the linked list <= 1000
1 <= x <= N

*/



// Function to delete the node at position x
Node* deleteNode(Node **head_ref, int x)
{
  //Your code here
  
  if(x==1)
  {
        (*head_ref)=(*head_ref)->next;
        return *head_ref;
  }
   
    Node* pre=NULL;
    Node* curr=*head_ref;
    Node* nxt=curr->next;
    
    int count=1;
    while(count<x)
    {
        
        pre=curr;
        curr=nxt;
        nxt=curr->next;
        count++;
    }
    if(nxt!=NULL)
    {
        Node* temp=pre;
        pre->next=nxt;
        nxt->prev=temp;
    }
    else
    {
        pre->next=NULL;
    }
    return *head_ref;
}
