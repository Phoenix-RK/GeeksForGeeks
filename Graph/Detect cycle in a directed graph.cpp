//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

Given a directed graph, the task is to complete the method isCyclic() to detect if there is a cycle in the graph or not. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.


*/



/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/


bool CycUtil(int i,bool* vis,bool* rec,vector<int> adj[])
{
    
  
   vis[i]=true;
   rec[i]=true;
        
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(rec[*it])
                return true;
            if(!vis[*it] && CycUtil(*it,vis,rec,adj))
                return true;
            
        }
   
    rec[i]=false;
    return false;
    
}


bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    
    bool *vis=new bool[V];
    bool *rec=new bool[V];
    
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
        rec[i]=false;
    }

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(CycUtil(i,vis,rec,adj))
                return true;
        }
    }
    return false;
}
