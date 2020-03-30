//Phoenix_RK

//MINIMUM NO OF COINS
/*
Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, Find the minimum number of coins and/or notes needed to make the change for Rs N.
Input:
1
43

Output:
20 20 2 1

*/

#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
 {
	//code
	int T,n;
	cin>>T;
	while(T--)
	{
	    int sum;
	    cin>>sum;
	    int a[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
	    int coins[10][sum+1];
	    
	    for(int i=0;i<=sum;i++)
	        coins[0][i]=i;
	    
	    for(int i=1;i<10;i++)
	    {
	        for(int j=0;j<=sum;j++)
	        {
	            if(j>=a[i])
	                coins[i][j]=min(coins[i-1][j],coins[i][j-a[i]]+1);
	           else
	             coins[i][j]=coins[i-1][j];
	        }	        
	    }
	    
	    int i=9,j=sum;
	    while(i>=0&&j>0)
	    {
	        if(coins[i][j]==coins[i-1][j])
	        i=i-1;
	        else
	        {
	            cout<<a[i]<<" ";
	            j=j-a[i];
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
