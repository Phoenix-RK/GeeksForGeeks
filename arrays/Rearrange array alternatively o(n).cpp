//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...


2
6
1 2 3 4 5 6
11 
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60
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
	   int a[n],b[n],i;
	   
	    for( i=0;i<n;i++)
	        cin>>a[i];
	  /*   1 2 3 4 5 
	       j       i
	     
	        
	       0 1 2 3 4 5 
	       6 1 5 2 4 3
	       
	       0 1 2 3 4
	       5 1 2 4 
	    */    
	   int k=0;
	    for(int i=n-1,j=0; i>=j ;i--,j++)
	    {
	        b[k++]=a[i];
	      
	        
	        if(k==n)
	          break;
	        
	        b[k++]=a[j];
	     }
	    
	    for( i=0;i<n;i++)
	        cout<<b[i]<<" ";
	    cout<<endl;
	
	}
	return 0;
}
