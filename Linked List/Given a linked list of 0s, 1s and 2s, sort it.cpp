//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

Example 1:

Input:
N = 8
value[] = {1,2,2,1,2,0,2,2}
Output: 0 1 1 2 2 2 2 2
Explanation: All the 0s are segregated
to the left end of the linked list,
2s to the right end of the list, and
1s in between.
Example 2:

Input:
N = 4
value[] = {2,2,0,1}
Output: 0 1 2 2
Explanation: After arranging all the
0s,1s and 2s in the given format,
the output will be 0 1 2 2.
Your Task:
The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement and returns the head of the modified linked list. The printing is done automatically by the driver code.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

*/



/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    // Add code here
    
    Node* p=head;
    Node* zero_s=NULL;
    Node* zero=NULL;
    Node* one_s=NULL;
    Node* one=NULL;
    Node* two_s=NULL;
    Node* two=NULL;
    while(head!=NULL)
    {
       // cout<<head->data<<" ";
        if(head->data==0)
        {
            if(zero==NULL)
            {
                zero_s=head;
                zero=head;
            }
            else
            {
                zero->next=head;
                zero=zero->next;
            }
        }
        
        else if(head->data==1)
        {
            if(one==NULL)
            {
                one_s=head;
                one=head;
            }
            else
            {
                one->next=head;
                one=one->next;
            }
        }
        
        else if(head->data==2)
        {
            if(two==NULL)
            {
                two_s=head;
                two=head;
            }
            else
            {
                two->next=head;
                two=two->next;
            }
        }
        head=head->next;
    }
    
    if(zero_s)
    {
        if(one_s)
        {
            zero->next=one_s;
            if(two_s)
            {
                one->next=two_s;
                two->next=NULL;
            }
            else
            one->next=NULL;
        }
        else
        {
            if(two_s)
            {
                zero->next=two_s;
                two->next=NULL;
            }
            else
            zero->next=NULL;
        }
        return zero_s;
    }
    else
    {
        if(one_s)
        {
            if(two_s)
            {
                one->next=two_s;
                two->next=NULL;
            }
            else
                one->next=NULL;
                
            return one_s;
        }
        else
        {
            return two_s;
        }
    }
}

