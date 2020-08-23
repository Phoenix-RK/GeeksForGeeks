//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

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

Expected Time Complexity: O(N) + O(M)
Expected Auxiliary Space: O(N) + O(M)
*/




struct Node* reverse(struct Node* head)
{
    struct Node* curr=head,*prev=NULL,*nxt=NULL;
    
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    return prev;
}
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
void print(struct Node* head)
{
    Node* s=head;
    while(s!=NULL)
    {
        cout<<s->data<<" ";
        s=s->next;
    }
    cout<<endl;
}
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
    
    Node* p=reverse(first);
    Node* q=reverse(second);
    Node* ans;
    int addition=0,iscarry=0,rem=0,carry=0,flag=0;
    while(p!=NULL && q!=NULL)
    {
        addition=p->data+q->data+carry;
        iscarry=addition/10;
        if(iscarry)
            carry=1;
        else
            carry=0;
        if(flag==0)
        {
            Node* temp=new Node(addition%10);
            temp->next=NULL;
            ans=temp;
            flag=1;
        }
        else
        {
            Node* temp=new Node(addition%10);
            temp->next=ans;
            ans=temp;
        }
        p=p->next;
        q=q->next;
    }
    if(carry)
    {
        Node* temp=new Node(1);
        temp->next=ans;
        ans=temp;
    }
    return ans;
}
