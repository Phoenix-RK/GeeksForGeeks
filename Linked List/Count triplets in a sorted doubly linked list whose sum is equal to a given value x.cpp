//Phoenix_RK


/*


Problem Statement
You have been given an integer ‘X’ and a non-decreasing sorted doubly linked list with distinct nodes, you are supposed to return the number of triplets in the list that sum up to the value ‘X’.
Input Format :
The first line contains a single integer ‘T’ denoting the number of test cases. The test cases follow.

The first line of each test case contains a single integer ‘X’.

The second line of the input contains the elements of the doubly linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.
Output Format:
For each test case, print in a new line the number of triplets which have the sum equal to ‘X’.
Note:
You don’t need to print anything; It has already been taken care of.
Constraints :
1 <= T <= 5
1 <= N <= 1000
-3*10^5 <= X <= 3*10^5
-10^5 <= data <= 10^5 and data != -1
Where ‘N’ is the number of nodes in the given linked list, and ‘X’ is the required triplet sum value.

Time limit: 1 sec
Sample Input 1:
2
13
-4 2 3 8 9 -1
5
-4 -2 3 4 5 -1
Sample Output 1:
2
2
Explanation To Sample Input 1:
In the first test case, there are two possible triplets {2,3,8} and {-4,8,9}, whose sum is 13.
In the second test case there are two triplets possible {-4,4,5} and {-2,3,4} whose sum is 5.
Sample Input 2:
2
-4
-3 8 10 -1
12
1 4 6 2 -1
Sample Output 2:
0
1
Explanation To Sample Input 2:
In the first test case, there is no triplet whose sum is -4.
In the second test case, there is only one triplet {6,4,2}, whose sum is 12.






*/

int check(Node* first,Node* second,int x)
{
    int count=0;
    while(first!=NULL && second!=NULL && first!=second && second->next!=first)
    {
        if(first->data+second->data==x)
        {
            count++;
            first=first->next;
            second=second->prev;
        }  
        else if(first->data+second->data<x)
            first=first->next;
        else
            second=second->prev;
    }
    
    return count;
}

int countAllTripletSum(Node *head, int x)
{
    //    Write your code here'
    if(head==NULL)
        return 0;
	int count=0;
    Node* curr=head,*last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    
    while(curr)
    {
        count+=check(curr->next,last,x-curr->data);       
        curr=curr->next;
    }
    
    return count;
    
}

