//Phoenix_RK
/*

Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.


1. find middle
2. split into LL
3.Reverse second LL
4 merge both ll
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
Node * find_mid(Node* head)
{
    
    Node *m=head;
    Node *n=m->next;
    while(n && n->next)
    {
        m=m->next;
        n=n->next->next;
    }
    
    return m;
}
void reverse(Node** root)
{
    Node *prev=NULL,*curr=*root,*last;
   

    while(curr)
    {
        last=curr->next;
        curr->next=prev;
        prev=curr;
        curr = last;
    }
    *root=prev;
    
}
void reorderList(Node* head) {
    // Your code here
    Node *mid=find_mid(head);

    Node *second=mid->next;
    Node *first=head;
    mid->next=NULL;
    
    reverse(&second);
    
   /* merge(first,second);
    1 2 5
    3 4 6
     5
     6
    
    1->3->2->4->5->6->n n 6-> n 5->n 4->6->n
    */
    while(first!=NULL && second!=NULL)
    {
        Node *temp1 = first->next,*temp2=second->next;
        first->next = second;
        second->next= temp1;
        first=temp1;
        second=temp2;
    }
 
}
