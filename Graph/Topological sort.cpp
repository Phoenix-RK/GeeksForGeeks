//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/topological-sort/1

Given a Directed Graph. Find any Topological Sorting of that Graph
*/


#include <bits/stdc++.h>

using namespace std;

int *topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, int res[], vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        int *res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array
*/
void dfs(int i,bool* vis, vector<int> adj[],stack<int>& s)
{
    
    vis[i]=true;
    for(auto it=adj[i].begin();it!=adj[i].end();it++)
    {
        if(!vis[*it])
            dfs(*it,vis,adj,s);
    }
    
    s.push(i);
}

int* topoSort(int V, vector<int> adj[]) {
    // Your code here
    stack<int> s;
    int *a=new int[V];
    bool *vis=new bool[V];
    
    for(int i=0;i<V;i++)
        vis[i]=false;
        
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,s);
        }
    }
    int j=0;
    while(!s.empty())
    {
        a[j++]=s.top();
        s.pop();
    }
    return a;   
}

