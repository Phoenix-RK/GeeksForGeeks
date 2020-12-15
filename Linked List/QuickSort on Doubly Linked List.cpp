//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/quicksort-on-doubly-linked-list/1#


Sort the given doubly linked list of size N using quicksort. Just complete the partition function using the quicksort technique.
 

Example 1:

Input:
LinkedList: 4->2->9
Output:
2 4 9

Example 2:

Input:
LinkedList: 1->4->9->2
Output:
1 2 4 9

Your Task:
Your task is to complete the given function partition(), which accepts the first and last node of the given linked list as input parameters and returns the pivot's address.
 

Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(1)
 

Constraints:
1 <= N <= 200

*/





/* a Node of the doubly linked list */


/*
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};
*/

/*
97  50  64  79  11  58
p                    r

58  50  11  79  64
            l,r
pivot =58


*/

Node* partition(Node *l, Node *h)
{
    //Your code goes here
    if(l==NULL || h==NULL || l==h)
        return l;

    int pivot = l->data;
    Node* store=l;
    
    while(l!=h->next)
    {
        while(l!=NULL && l->data <=pivot && l!=h->next)
        {
            l=l->next;
         
        }
        while(h!=NULL && h->data>pivot && l!=h->next)
        {
            h=h->prev;
          
        }
        if(l!=NULL && h!=NULL && l!=h->next)
        {
            swap(&(l->data),&(h->data));
         
        }
        
    }
    swap(&(h->data),&(store->data));

    return h;
}

