//Phoenix_RK


/*
Given N nodes and E edges of a connected undirected graph. The task is to do depth first traversal of the graph.

Note: Use recursive approach
*/

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/


void dfs(int s, vector<int> g[], bool vis[])
{
    
    // Your code here
    vis[s]=true;
    cout<<s<<" ";
    for(auto it=g[s].begin();it!=g[s].end();it++)
    {
        if(!vis[*it])
        {
            dfs(*it,g,vis);
        }
    }

}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0,g,vis);
        
        cout<<endl;

    }
}  // } Driver Code Ends
