//Phoenix_RK
//Count ways to reach the n'th stair
/*
There are N stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
Input:
3
4
10
24

Output:
5
89
75025

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int T,n;
	cin>>T;
	int a[100001];
	    
	a[0]=1;
	a[1]=1;
	    
    for(int i=2;i<=100000;i++)
    {
        a[i]=(a[i-1]+a[i-2])%1000000007;
    }
	    
	while(T--)
	{
	    cin>>n;
	  
	    cout<<a[n]<<endl;
	}
	return 0;
}
