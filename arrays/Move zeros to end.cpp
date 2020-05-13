//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array/0

Given an array A of positive integers. Push all the zero’s of a given array to the end of the array.

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
   int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        
	  // 1 4 0 0 5
	  for(int i=0;i<n;i++)
	    {
	        if(a[i]==0)
	        {
	            int j=i+1;
	            while(a[j]==0 && j!=n-1)
	                j++;
	           
	           int temp=a[i];
	           a[i]=a[j];
	           a[j]=temp;
	           
	           if(j==n-1)
	           {
	               i=n;
	           }
	         
	        }
	    }
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	   cout<<endl;
	}
	return 0;
}
