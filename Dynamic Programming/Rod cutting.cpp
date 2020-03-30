//Phoenix_RK
/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example:
Input:
1
8
1 5 8 9 10 17 17 20

Output:
22

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
 int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int price[n];
	    for(int i=0;i<n;i++)
	        cin>>price[i];
	        
	    
	    int profit[n+1][n+1];
	    
	    for(int i=0;i<=n;i++)
	    {
	        profit[i][0]=0;
	        profit[0][i]=0;
	    }
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=n;j++)
	        {
	            if(j>=i)
	            profit[i][j]=max(profit[i-1][j],price[i-1]+profit[i][j-i]);
	        
	            else
	            profit[i][j]=profit[i-1][j];
	        }
	    }
	 /*   
	     for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=n;j++)
	        {
	            cout<<profit[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	   */ 
	    cout<<profit[n][n]<<" ";
	    cout<<endl;
	
	}
	return 0;
}
