//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1



Given a linked list of N nodes. The task is to reverse this list.



*/

//iterative
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
  Node* nxt,*curr,*prev;
  nxt=head;
  curr=head;
  prev=NULL;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}

//recursive


Node * res=NULL;
struct Node* rev(struct Node* head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
    {
        res=head;
        return res;
    }
    
    struct Node* sub=rev(head->next);
    sub->next=head;
    head->next=NULL;
    return head;
}
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    rev(head);
    return res;
}
