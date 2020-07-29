//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/binary-array-sorting/0


Given a binary array A[] of size N. The task is to arrange array in increasing order.

Note: The binary array contains only 0  and 1.

Input:
The first line of input contains an integer T, denoting the testcases. Every test case contains two lines, first line is N(size of array) and second line is space separated elements of array.

Output:
Space separated elements of sorted arrays. There should be a new line between output of every test case.

Constraints:
1 < = T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
5
1 0 1 1 0
10
1 0 1 1 1 1 1 0 0 0

Output:
0 0 1 1 1
0 0 0 0 1 1 1 1 1 1


*/


/*
Idea : Use two pointers
*/
#include<bits/stdc++.h>
using namespace std;
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
    	int start=0,end=n-1;
    	while(start<end)
    	{
    	    while(a[start]==0)
    	        start++;
    	    while(a[end]==1)
    	        end--;
    	    if(start<end)
    	    {
    	        int temp=a[start];
    	        a[start]=a[end];
    	        a[end]=temp;
    	    }
    	}
    	
    	for(int i=0;i<n;i++)
    	    cout<<a[i]<<" ";
    	    
    	cout<<endl;
	
	}
	return 0;
}
