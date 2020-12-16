//Phoenix_RK


/*


Given a doubly linked list containing n nodes, where each node is at most k away from its target position in the list. The problem is to sort the given doubly linked list.
For example, let us consider k is 2, a node at position 7 in the sorted doubly linked list, can be at positions 5, 6, 7, 8, 9 in the given doubly linked list.




*/
struct compare { 
	
bool operator()(Node* first,Node* second)
{
//first is the ele at top, second is ele to be inserted 
//ele is inserted on top only when first is greater than second
	return first->data > second->data;

}
};

Node* k_sorted(Node* head,int k)
{
	if(head==NULL)
		return head;
	
	Node* res=NULL;
	Node* last;
	priority_queue<Node*, vector<Node*>, compare> pq;
	
	while(head!=NULL)
	{
	    cout<<"head->data= "<<head->data<<endl;
		pq.push(head);
		if(pq.size()==k+1)
		{	
		    cout<<"pq.top="<<pq.top()->data<<endl;
			if(res==NULL)
			{
				res=pq.top();
				res->prev=NULL;
				last=res;
			}

			else
			{
				last->next=pq.top();
				pq.top()->prev=last;
				last=pq.top();
			}
			pq.pop();
		}
		head=head->next;
	}

	while(!pq.empty())
	{
	     cout<<"pq.top="<<pq.top()->data<<endl;
		if(res==NULL)
		{
			res=pq.top();
			res->prev=NULL;
			
			last=res;
			last->next=NULL;
		}

		else
		{
			last->next=pq.top();
			pq.top()->prev=last;
			last=pq.top();
			last->next=NULL;
		}
      pq.pop();

	}

	return res;

}
