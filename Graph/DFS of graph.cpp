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

void dfsUtil(vector<int> g[],int curr,vector<int> &res,bool vis[])
{
 
    vis[curr]=true;
    res.push_back(curr);
    vector<int>::iterator it;
    for(it=g[curr].begin();it!=g[curr].end();it++)
    {
        if(!vis[*it])
        {
            dfsUtil(g,*it,res,vis);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    // Your code here
    bool vis[N];
    memset(vis,false,sizeof(vis));
    vector<int> res;
    dfsUtil(g,0,res,vis);
    return res;
}
