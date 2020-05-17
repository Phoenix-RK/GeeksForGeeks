//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
Note: Try not to use extra space. Expected time complexity is O(N). The nodes are arranged in a sorted way.

*/

// root: head node
Node *removeDuplicates(Node *root)
{
 // your code goes here
 Node *head=root;
 while(head->next!=NULL)
 {
     if (head->data==head->next->data)
     {
         head->next=head->next->next;
     }
     else
     {
         head=head->next;
     }
     
 }
 return root;
}
