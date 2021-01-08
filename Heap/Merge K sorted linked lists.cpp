//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#


Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

Example 1:

Input:
K = 4
value = {{1,2,3},{4 5},{5 6},{7,8}}
Output: 1 2 3 4 5 5 6 7 8
Explanation:
The test case has 4 sorted linked 
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
1->2->3->4->5->5->6->7->8.
Example 2:

Input:
K = 3
value = {{1,3},{4,5,6},{8}}
Output: 1 3 4 5 6 8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
1->3->4->5->6->8.
Your Task:
The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)
Note: n is the maximum size of all the k link list

Constraints
1 <= K <= 103

*/


/*Linked list Node structure

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

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
struct compare { 
	
bool operator()(Node* first,Node* second)
{
//first is the ele at top, second is ele to be inserted 
//ele is inserted on top only when first is greater than second
	return first->data > second->data;

}
};

Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       
       priority_queue<Node*, vector<Node*>, compare> pq;
       
       for(int i=0;i<N;i++)
       {
           
           if(arr[i]==NULL)
                continue;
                
            Node* curr=arr[i];
            pq.push(curr);
       }
       
       Node* res=NULL,*last;
       
       while(!pq.empty())
       {
           if(res==NULL)
           {
               res=pq.top();
               if(res->next)
                pq.push(res->next);
                
               last=res;
               last->next=NULL;
           }
           else
           {
               last->next=pq.top();
               last=last->next;
              
               if(last->next)
                   pq.push(last->next);
                   
               last->next=NULL;
           }
           pq.pop();
       }
       
       return res;
}



