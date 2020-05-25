//Phoenix_RK

/*
Given a undirected graph, the task is to complete the method isCyclic() to detect if there is a cycle in the undirected graph or not.



Idea:


1) Traverse through each node of the graph using DFS and keep track of parent of the corresponding node.
2) At some point , if for a particular node its adjacent node is visited and that adj node is not its parent , then there is a cycle in the graph.


note:
In undirected, a node's adj node can be visited if and only if , that adj node is the parent of the particular node that is being considered. 

bcoz,
0->1
1->0

0 is visited before 1

*/


/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool cycle(int i,bool *vis,vector<int> adj[],int parent)
{
    vis[i]=true;
    
    for(auto it=adj[i].begin();it!=adj[i].end();it++)
    {
        if(!vis[*it])
        {
            if(cycle(*it,vis,adj,i))
                return true;
        }
        else if(*it!=parent)
            return true;
    }
    return false;
}


bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   
   
   bool *vis= new bool[V];
   
   for(int i=0;i<V;i++)
    vis[i]=false;
    
   for(int i=0;i<V;i++)
   {
       if(!vis[i] && cycle(i,vis,adj,-1))
        return true;
   }
   return false;
   
}
