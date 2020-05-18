//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


Given N and E, the number of nodes and edges in a directed graph. The task is to do Breadth First Search of this graph.

*/


#include <bits/stdc++.h>

using namespace std;

void bfs(int s, vector<int> g[], vector<bool> &vis, int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        vector<bool> vis(N, false);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        bfs(0, adj, vis, N);
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int s, vector<int> g[], vector<bool> &vis, int N) {

    // Your code here
    
    list<int> queue;
    vis[s]=true;
    queue.push_back(s);
    
    while(!queue.empty())
    {
        int s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        
        
        for(auto it=g[s].begin();it!=g[s].end();it++)
        {
            if(!vis[*it])
            {
                vis[*it]=true;
                queue.push_back(*it);
            }
        }
    }
  
    
    
    
}
