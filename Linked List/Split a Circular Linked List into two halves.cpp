//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1#


Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

Input:
You have to complete the method which takes 3 argument: The address of the head of the linked list , addresses of the head of the first and second halved resultant lists.. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Set the *head1_ref and *head2_ref to first resultant list and second resultant list respectively.

Constraints:
1<=T<=100
2<=N<=100

Example:
Input:
2
3
1 5 7
4
2 6 1 5

Output:
1 5
7
2 6
1 5

Explanation:
Testcase 2: Distributing the given circular linked list into two halves makes two linked list as 2, 6 and 1, 5.



*/




/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    
    Node* slow=head,*fast=head;
    
    while(fast->next!=head && fast->next->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1_ref=head;
    *head2_ref=slow->next;


    if(fast->next==head)
    fast->next=slow->next;
    else 
    fast->next->next=slow->next;
    
    slow->next=head;
}

