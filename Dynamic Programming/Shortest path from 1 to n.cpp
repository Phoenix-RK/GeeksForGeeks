//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0

Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.



*/


#include<bits/stdc++.h>
using namespace std;
int min (int a,int b)
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
	    cin>>n;
	    int res=0;
	    int a[n+1];
	    a[0]=0;
	    a[1]=0;
	    for(int i=2;i<=n;i++)
	    {
	        
	        if(i%3==0)
	          a[i]= min(a[i/3]+1, a[i-1]+1);
	        else
	          a[i]= a[i-1]+1;
	          
	       //   cout<<a[i]<<" ";
	    }
	    cout<<a[n]<<endl;
	    
	}
	return 0;
}
