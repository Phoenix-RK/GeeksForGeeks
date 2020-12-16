//Phoenix_RK


/*


Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in doubly linked list whose sum is equal to given value x, without using any extra space ? 

Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
        x = 7
Output: (6, 1), (5,2)


Expected time complexity is O(n) and auxiliary space is O(1).

*/


void pairSum(Node* head,int sum)
{

if(head==NULL || head->next=NULL)
	return;

Node* first=head;
Node* second=head;

while(second->next!=NULL)
	second=second->next;

while(first!=second && second->next!=first)
{
	if(first->data+second->data==sum)
	{
		cout<<first->data<<" "<<second->data<<endl;
		first=first->next;
		second=second->prev;

	}
	else if(first->data+second->data<sum)
		first=first->next;

	else 
		second=second->prev;
}


}
