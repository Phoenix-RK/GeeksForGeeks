//Phoenix_RK
/*

Given an array arr[] of N integers. Do the following operation n-1 times. For every Kth operation:

Right rotate the array clockwise by 1.
Delete the (n-k+1)th last element.
Now, find the element which is left at last.


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
      if(n==1)
        cout<<a[0]<<endl;
	  else if(n%2)
	    {
	        int ind=floor((n-3)/4)+2;
	        cout<<a[ind]<<endl;
	    }
	    else
	    {
	         int ind=floor((n-2)/4)+1;
	         cout<<a[ind]<<endl;
	        
	    }
	}
	return 0;
}
