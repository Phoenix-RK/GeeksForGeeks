//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1

Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller than or equal to length of the linked list.

Example 1:

Input:
N = 8
value[] = {1,2,3,4,5,6,7,8}
k = 4
Output: 5 6 7 8 1 2 3 4
*/



Node* rotate(Node* head, int k)
{
    // Your code here
    if(head==NULL)
        return NULL;
        
    Node* end=head;
    while(end->next!=NULL)
    {
        end=end->next;
    }
    end->next=head;
 
    while(k!=1)
    {
        head=head->next;
        k--;
    }
    Node*nxt=head->next;
    head->next=NULL;
    
    return nxt;
    
    
}

