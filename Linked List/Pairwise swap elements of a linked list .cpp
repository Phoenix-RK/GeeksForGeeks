//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1




Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
Output: 2 1 4 2 6 5 8 7
Explanation: After swapping each pair
considering (1,2), (2, 4), (5, 6).. so
on as pairs, we get 2, 1, 4, 2, 6, 5,
8, 7 as a new linked list.
Your Task:
The task is to complete the function pairWiseSwap() which takes the head node as the only argument and returns the modified head.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/



/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/
/*
 N<-1<-2  N<-2<-4 <-5<-6  N<-7<-8 c 
    h  p     h  p   h  p        p
                      2 1 4 2 6 5  8 7 N

 prev=null
 cuur= 1
*/
Node* pairWiseSwap(struct Node* head) {
    // The task is to complete this method
    
    Node* curr=head,*prev=NULL,*nxt=NULL;
    int count=0;
    while(curr!=NULL && count!=2)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        count++;
    }
    if(curr!=NULL)
        head->next=pairWiseSwap(nxt);
    else
        head->next=NULL;
        
    return prev;
    
}
