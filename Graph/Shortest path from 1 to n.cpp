//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0


Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

Input: 
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

Each test case contains a value of n. 

Output: 
Print the number of edges in the shortest path from 1 to n.

Constraints:
1<=T<=30
1<=n <=1000

Example:
Input:
2
9
4

Output:
2
2

 


*/


#include<bits/stdc++.h>
using namespace std;
#define max 10001
int n;
int a[10001][10001];

int path(int a[max][max],int n)
{
    int dist[n+1];
    bool vis[n+1];
    int parent[n+1];
    
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dist[i]=INT_MAX;
    }
    
    dist[1]=0;
    parent[1]=-1;
    
    for(int i=1;i<=n-1;i++)
    {
        
        int minv=INT_MAX,min_ind;
        for(int x=1;x<=n;x++)
        {
            if(vis[x]==false && dist[x]<minv)
            {
                minv=dist[x];
                min_ind=x;
            }
        }
        
        vis[min_ind]=true;
        
        for(int j=1;j<=n;j++)
        {
            if(vis[j]==false && a[min_ind][j]!=0 &&  dist[min_ind] != INT_MAX && dist[min_ind] + a[min_ind][j] < dist[j]) 
            {
                dist[j]=dist[min_ind]+a[min_ind][j];
            }
        }
    }
    
  /* for(int i=1;i<=n;i++)
        cout<<dist[i]<<" ";*/
    return dist[n];
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	 
	    cin>>n;
	   memset(a,0,sizeof(a));
	   
	   for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=n;j++)
	       {
	           if(j==i+1 || j==3*i)
	                a[i][j]=1;
	       }

	   }
	  /* 
	    for(int i=1;i<=n;i++)
	   {
	       for(int j=1;j<=n;j++)
	           cout<<a[i][j]<<" ";
	       
	       cout<<endl;
	   }*/
	   
	  cout<<path(a,n)<<endl;
	
	}
	return 0;
}
