//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

Input:
N = 2
valueN[] = {6,3}
M = 1
valueM[] = {7}
Output: 7 0
Explanation: For the given two linked
list (6 3) and (7), after adding the
two linked list resultant linked list
will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the new list.        

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(Max(N,M))

Constraints:
1 <= N, M <= 5000



*/



int length(struct Node* head)
{
    if(head==NULL)
        return 0;
    struct Node* p=head;
    int count=0;
    while(p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}

void add(struct Node* first,struct Node* second,int& carry)
{
    if(first==NULL)
        return;
        
    add(first->next,second->next,carry);
    
    first->data=first->data+second->data+carry;
    carry=first->data/10;
    first->data=first->data%10;
    //cout<<first->data<<" "<<carry<<endl;
    
}
//Recursive
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    // code here
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
        
    int l1=length(first);
    int l2=length(second);
    if(l1<l2)
    {
        int diff=l2-l1;
        while(diff--)
        {
            struct Node *temp= new Node(0);
            temp->next=first;
            first=temp;
        }
    }
    else if(l2<l1)
    {
        int diff=l1-l2;
        while(diff--)
        {
            struct Node *temp= new Node(0);
            temp->next=second;
            second=temp;
        }
    }
    

    int carry=0;
    
    add(first,second,carry);
    
    if(carry)
    {
        Node* temp=new Node(1);
        temp->next=first;
        first=temp;
    }
    return first;
}

