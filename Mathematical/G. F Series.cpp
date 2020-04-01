//Phoenix_RK
/*
Siddhant made a special series and named it as G.F Series.The series follows this trend  Tn=(Tn-2)2-(Tn-1)  in which the first and the second term are 0 and 1 respectively.Help Siddhant to find  upto N terms of the series .
Input:
3
3
6
2

Output:
0 1 -1
0 1 -1 2 -1 5 
0 1




*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
  long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    long long int a[n];
	    a[0]=0;
	    a[1]=1;
	    if(n==1)
	    cout<<"0";
	 
	    
	    else
	    {
    	    cout<<"0 1 ";
    	    
    	    for(long long int i=2;i<n;i++)
    	    {
    	        a[i]=(a[i-2]*a[i-2])-a[i-1];
    	        cout<<a[i]<<" ";
    	    }
	    }
	    cout<<endl;
	
	}
	return 0;
}
