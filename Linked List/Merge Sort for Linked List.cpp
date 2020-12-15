//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1




Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(1)

Constraints:
1 <= T <= 100
1 <= N <= 105



*/

Node *sortedMerge(Node *a,Node *b)
 {
     Node *result;
     
     if(a==NULL)
     return b;
     
     else if(b==NULL)
     return a;
     
     else
     {
         
         if(a->data<=b->data)
         {
             result=a;
             result->next=sortedMerge(a->next,b);
             
          }
          else {
             result=b;
             result->next=sortedMerge(a,b->next);
              
          }
         
     }
     return result;
     
 }
Node* mergeSort(Node* head) {
    // your code here
    
    if(!head || !head->next)
        return head;
        
    Node* slow=head;
    Node* fast=head->next;
    
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    Node* mid=slow->next;
    slow->next=NULL;
    
    return sortedMerge(mergeSort(head),mergeSort(mid));
}
