//Phoenix_RK


/*
Given a directed graph, the task is to complete the method isCyclic() to detect if there is a cycle in the graph or not. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.
*/



/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

//white-0....grey-1....black=2


bool CycUtil(int i,int* color,vector<int> adj[])
{
    color[i]=1; //node is being seen
        
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            if(color[*it]==1)
                return true;
            if(color[*it]==0 && CycUtil(*it,color,adj))
                return true;

        }

    color[i]=2; //completed seeing the node
    return false;
    
}


bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    
  
    int *color=new int[V];
    
    for(int i=0;i<V;i++)
        color[i]=0; //all nodes not seen 
        
    for(int i=0;i<V;i++)
    {
        if(color[i]==0)
        {
            if(CycUtil(i,color,adj))
                return true;
        }
    }
    return false;
}
