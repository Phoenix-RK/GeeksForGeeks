//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Input:
First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the linked list elements.

Output:
For each testcase, there will be a single line of output which contains the linked list with every k group elements reversed.

User Task:
The task is to complete the function reverse() which should reverse the linked list in group of size k.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Example:
Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4

Explanation:
Testcase 1: Since, k = 4. So, we have to reverse every group of four elements. Modified linked list is as 4, 2, 2, 1, 8, 7, 6, 5.

*/


struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    
    struct node* prev=NULL,*curr=head,*nxt=NULL;
    int count=0;
    while(curr!=NULL && count<k)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        count++;
    }
    if(curr!=NULL)
        head->next=reverse(nxt,k);
    else
        head->next=nxt;
        
    return prev;
    
}
