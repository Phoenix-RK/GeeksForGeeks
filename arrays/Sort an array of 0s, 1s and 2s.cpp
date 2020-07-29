//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0

Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

Output: 
For each testcase, print the sorted array.

Constraints:
1 <= T <= 500
1 <= N <= 106
0 <= Ai <= 2

Example:
Input :
2
5
0 2 1 2 0
3
0 1 0

Output:
0 0 1 2 2
0 0 1

Explanation:
Testcase 1: After segragating the 0s, 1s and 2s, we have 0 0 1 2 2 which shown in the output.


*/

/*
Idea:

Use three pointers(low, mid, high)

1) index0 to mid is known
2) mid to high is unknown
3) index0 to low is zero
4) low to mid is one
5) high to lastindex is two



*/

#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	    cin>>a[i];
    	    
    	int i=0,low=0,mid=0,high=n-1,temp;
    	
    	while(mid<=high && i<n)
    	{
    	    if(a[i]==0)  
    	    {
    	        swap(&a[i],&a[low]);
    	        low=low+1; // since after swap a 0 is placed, increment the low(to indicate that many 0s are present before that low)
    	        mid=mid+1; //since index0 to mid indicates the known segment, increment the mid to indicate that one more element has been known and is in place.
    	        i++;
    	        continue;
    	    }
    	    
    	    else if(a[i]==1)
    	    {
    	        mid=mid+1; //since index0 to mid indicates the known segment, increment the mid to indicate that one more element has been known and is in place.
//should not increment low, as low to mid is 1s range
    	        i++;
    	    }
    	    
    	    else if(a[i]==2)
    	    {
    	        swap(&a[i],&a[high]);
    	        high=high-1;// since high to lastindex indicate the 2s range decrement the high to hold the newly found 2.
    	        //after swap, the element at the ith position would not have been encountered. Hence do not increment i
    	    }
    	    
    	  
    	}
    
    	
    	for(int i=0;i<n;i++)
    	    cout<<a[i]<<" ";
    	    
    	cout<<endl;
	}
	return 0;
}
