//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1

Given a linked list, you have to perform the following task:

Extract the alternative nodes from starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
​Example 1:

Input:
LinkedList = 10->4->9->1->3->5->9->4
Output: 10 9 3 9 4 5 1 4
Explanation: Reversing the alternative
nodes from the given list, and then
appending them to the end of the list
results in a list with the elements as
10 9 3 9 4 5 1 4.
​Example 2:

Input:
LinkedList = 1->2->3->4->5
Output: 1 3 5 4 2 
Explanation:
Your Task:
The task is to complete the function rearrange() which should rearrange the list as required.

Note: Try to solve the problem without using any extra memory.
*/





void rearrange(struct Node *head)
{
    //add code here
   
    Node* temp=head;
    Node* p=temp->next;
    Node* q=p;
    
    while(p!=NULL)
    {
        p=temp->next;
        
        if(p!=NULL)
        {
            temp->next=temp->next->next;
            if(p->next!=NULL)
                p->next=p->next->next;
            if(temp->next!=NULL)
                temp=temp->next;
            
            p=p->next;
        }
    }
    
    Node* curr=q;
    Node* prev=NULL,*nxt=NULL;
    
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    
    temp->next=prev;
}
