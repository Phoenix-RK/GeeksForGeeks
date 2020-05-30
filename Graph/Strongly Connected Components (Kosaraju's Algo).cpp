//Phoenix_RK

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/


/*

Kosaraju's Algoithm:

	1.DFS and push into stack
	2.Transpose
	3.Do DFS again

*/


void dfs(int i,bool visited[],stack<int> &s,vector<int> adj[])
{
    
    visited[i]=true;
    
    for(auto it=adj[i].begin();it!=adj[i].end();it++)
    {
        if(!visited[*it])
            dfs(*it,visited,s,adj);
    }
    
    s.push(i);
    
}


void dfs2(int i,bool visited[],vector<int> g[])
{
    
    visited[i]=true;
    for(auto it=g[i].begin();it!=g[i].end();it++)
    {
        if(!visited[*it])
            dfs2(*it,visited,g);
    }
    
}


int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    
    bool *visited=new bool[V];
    
  /*    for(int i=0;i<V;i++)
    {
        cout<<i<<" ";
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
           {
             
               cout<<*it<<" ";
           }
           cout<<endl;
    }
*/

    for(int i=0;i<V;i++)
        visited[i]=false;
        
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
            dfs(i,visited,s,adj); // to store elements in the stack according to their finish time...element at top of the stack takes longest finish time
    }

    vector<int>g[V];

    //Transpose (reverse the directions of the edges of the graph
    for(int i=0;i<V;i++)
    {
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
           {
               g[*it].push_back(i);
               
           }
    }
  /*    for(int i=0;i<V;i++)
    {
        cout<<i<<" ";
        for(auto it=g[i].begin();it!=g[i].end();it++)
           {
             
               cout<<*it<<" ";
           }
           cout<<endl;
    }*/
    
     for(int i=0;i<V;i++)
        visited[i]=false;
 
     int count=0;
     while(!s.empty())
     {
         int v=s.top();
         s.pop();
         if(!visited[v])
          {
              dfs2(v,visited,g);
              count++;
          }
         
     }
    return count;
}

// { Driver Code Starts.

int main()
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int a,b ;
   	    cin>>a>>b;
   	    int m,n;
   	    vector<int> adj[a+1];
        for(int i=0;i<b;i++){
            cin>>m>>n;
            adj[m].push_back(n);
        }
        // exit(0);
        cout<<kosaraju(a, adj)<<endl;
    }
    return 0;
}  // } Driver Code Ends
