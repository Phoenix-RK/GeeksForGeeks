//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Return the no. of times search_for value is there in a linked list.
  The input list will have at least one element  
  Node is defined as 
  struct node
  {
     int data;
     struct node *next;
  }
*/

int count(struct node* head, int search_for)
{
//add your code here
struct node *p=head;
int times=0;

while(p!=NULL)
{
    if(p->data==search_for)
    times++;
    
    p=p->next;
}

return times;
}
