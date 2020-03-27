//Phoenix_RK
/*
Given an array, cyclically rotate an array by one.

Example:
Input:
2
5
1 2 3 4 5
8
9 8 7 6 4 2 1 3

Output:
5 1 2 3 4
3 9 8 7 6 4 2 1

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n;
	cin>>t;
	
	while(t--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        if(i==n-1)
	        cin>>a[0];
	        else
	        cin>>a[i+1];
	    }
	   
	
	    for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	        
	   cout<<endl;
	    
	}
	return 0;
}
