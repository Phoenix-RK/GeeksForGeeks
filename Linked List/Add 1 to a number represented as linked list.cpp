//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#





A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.

Example 1:

Input:
LinkedList: 4->5->6
Output: 457 
Example 2:

Input:
LinkedList: 1->2->3
Output: 124 
Your Task:
Your task is to complete the function addOne() which takes the head of the linked list as the only argument and returns the head of the modified linked list. The driver code prints the number.
Note: The head represents the left-most digit of the number.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 101000



*/


//User function template for C++

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
void add(Node* head,int& carry)
{
    if(!head)
        return ;
    
    add(head->next,carry);
    
    head->data+=carry;
    carry=head->data/10;
    head->data=head->data%10;
    
    
}

Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    int carry=1;
    
    add(head,carry);
    
    if(carry)
    {
        Node* temp=new Node(1);
        temp->next=head;
        return temp;
    }
    else
        return head;
    
    
}



