/*
//Phoenix-RK


Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.



*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 
 Node *zigZack(Node* head);


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *ans = zigZack(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/


Node *zigZack(Node* head)
{
 // your code goes here
 
 bool flag=true;
 Node *p=head;
 
 while(p->next!=NULL)
 {
     if(flag)
     {
         if(p->data>p->next->data)
         {
             int temp=p->data;
             p->data=p->next->data;
             p->next->data=temp;
         }
         
     }
     else if(!flag)
     {
          if(p->data<p->next->data)
         {
             int temp=p->data;
             p->data=p->next->data;
             p->next->data=temp;
         }
         
     }
     p=p->next;
     flag=!flag;
 }
 return head;
}
