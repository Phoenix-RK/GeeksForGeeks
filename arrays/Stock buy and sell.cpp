//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0


The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

*/

#include<bits/stdc++.h>
using namespace std;

void buy_and_sell(int a[],int n)
{
    int buy[n],sell[n],count=0;
    
    int i=0;
    
    while(i<n-1)
    {
        while(i<n-1 && a[i]>=a[i+1])
            i++;
        if(i==n-1)
            break;
            
        buy[count] = i++;
        
        while(i<n && a[i]>=a[i-1])
            i++;
            
        sell[count] = i-1;
        
        count++;
            
        
    }
    
    if(count==0)
    {
        cout<<"No Profit";
        return;
    }
    
    for(int i=0;i<count;i++)
    {
        cout<<"("<<buy[i]<<" "<<sell[i]<<") ";
    }
    return;
    
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
    	
    	int a[n];
    	
    	for(int i=0;i<n;i++)
    	{
    	    cin>>a[i];
    	}
	    
	    buy_and_sell(a,n);
	    cout<<endl;
	
	}
	return 0;
}
