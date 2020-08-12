//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/count-the-paths/0

Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print the count of all paths from given ‘s’ to ‘d’.



*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;



void dfs(vector<int> V[], bool* vis, int src,int des,int& res)
{
   
    
    vis[src]=true;
    
    if(src==des)
        res++;
  
    for(auto it=V[src].begin();it!=V[src].end();it++)
    {
        if(!vis[*it])
        {
            
            dfs(V,vis,*it,des,res);
        }
        
    }
    
    vis[src]=false;
}
int main()
 {
	//code
	int T,n;
	cin>>T;
	
	while(T--)
	{
	    
	    int e,x,y,res=0,src,des;
	    cin>>n>>e;
	    vector<int> V[n];
	    for(int i=0;i<e;i++)
	    {
	        cin>>x>>y;
	        V[x].push_back(y);
	    }
	    cin>>src>>des;
	   
	       bool* vis = new bool(n);
	       for(int i=0;i<n;i++)
	          vis[i]=false;
	       dfs(V,vis,src,des,res);
	       cout<<res<<endl;
	   
	  
	}
	return 0;
}
