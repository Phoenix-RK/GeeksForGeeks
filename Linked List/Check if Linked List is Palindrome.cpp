//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.
Your Task:
The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

Expected Time Complexity: O(N)

*/




/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    if(head==NULL)
        return true;
    stack<int> s;
    Node *p=head;
    while(p!=NULL)
    {
        s.push(p->data);
        p=p->next;
    }
    while(head!=NULL)
    {
        if(s.empty())
            return false;
        int x=s.top();
        s.pop();
        if(x!=head->data)
            return false;
        head=head->next;
    }
    if(!s.empty())
        return false;
    return true;
}

