//Phoenix_RK
/*
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

*************************************************
1 101 2 3 100 4  5

1 101 2 3 100 4  5
1 102 3 6 106 10 15

*************************************************

*/
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n],sum[n],maxs;
	    for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	       sum[i]=a[i];
	   }
	   maxs=a[0];
	   
	   for(int i=1;i<n;i++)
	   {
	       for(int j=0;j<i;j++)
	       {
	           if(a[i]>a[j])
	           {
	               sum[i]=max(sum[i],sum[j]+a[i]);
	               if(sum[i]>maxs)
	               maxs=sum[i];
	           }
	           
	       }
	   }
	    cout<<maxs<<endl;
	
	}
	return 0;
}
