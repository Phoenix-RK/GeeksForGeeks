//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0

Given an array A[] of N numbers and another number x, determine whether or not there exist three elements in A[] whose sum is exactly x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains n and x. Next line contains array elements.

Output:
Print 1 if there exist three elements in A whose sum is exactly x, else 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 103
1 ≤ A[i] ≤ 105

Example:
Input:
2
6 13
1 4 45 6 10 8
5 10
1 2 4 3 6

Output:
1
1

Explanation:
Testcase 1: There is one triplet with sum 13 in the array. Triplet elements are 1, 4, 8, whose sum is 13.


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
	    int n,key;
    	cin>>n>>key;
    	int a[n];
    	
    	for(int i=0;i<n;i++)
    	    cin>>a[i];
        	    
        sort(a,a+n);
         
    	    int flag=0;
    	   
    	   for(int k=n-1;k>=0;k--)
    	   {
    	       int j=k-1,i=0;
    	       while(i<j)
    	       {
        	       if(a[i]+a[j]==key-a[k])
        	       {
        	           flag=1;
        	           cout<<"1"<<endl;
        	           break;
        	       }
        	       if(a[i]+a[j]>key-a[k])
        	       {
        	           j--;
        	       } 
        	       if(a[i]+a[j]<key-a[k])
        	       {
        	           i++;
        	       }
    	       }
    	       if(flag)
    	       break;
    	   }
    
	    if(flag==0)
	    {
	        cout<<"0"<<endl;
	    }
	}
	return 0;
}
