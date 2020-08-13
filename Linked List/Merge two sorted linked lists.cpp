//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1



Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,]
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105

*/



Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    Node *s;
    if(head_A==NULL)
        return head_B;
    if(head_B==NULL)
        return head_A;
        
    if(head_A->data<head_B->data)
    {
        s = head_A;
        s->next = sortedMerge(head_A->next,head_B);
    }
    else
    {
        s = head_B;
        s->next = sortedMerge(head_A,head_B->next);
    }
    
    return s;
}  
