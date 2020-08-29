//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


Given a weighted, undirected and connected graph. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. The first line of each testcase contains two integers V (starting from 1), E denoting the number of nodes and number of edges. Then in the next line are 3*E space separated values a b w where a, b denotes an edge from a to b and w is the weight of the edge.

Output:
For each test case in a new line print the sum of weights of  the edges of the Minimum Spanning Tree formed of the graph.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function  spanningTree() which takes number of vertices V and the number of edges E and a graph graph as inputs and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree.
Note: Please note that input of graph is 1-based but the adjacency matrix is 0-based.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

Constraints:
1 <= T <= 100
2 <= V <= 1000
V-1 <= E <= (V*(V-1))/2
1 <= a, b <= N
1 <= w <= 1000
Graph is connected and doesn't contain self loops & multiple edges.

Example:
Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5

Example:
Testcase 1:  Sum of weights of edges in the minimum spanning tree is 4.


*/



// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    
    int dist[V];
    int parent[V];
    bool visited[V];
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
    }
  
    
    parent[0]=-1;
    dist[0]=0;
    
    for(int i=0;i<V-1;i++)
    {
       
        int minv=INT_MAX,min_ind;
        for(int x=0;x<V;x++)
        {
            if(dist[x]<minv && visited[x]==false)
            {
                minv=dist[x];
                min_ind=x;
            }
        }

         visited[min_ind]=true;
        
        for(int j=0;j<V;j++)
        {
            if(graph[min_ind][j] && visited[j]==false && graph[min_ind][j]<dist[j])
            {
                parent[j]=min_ind;
                dist[j]=graph[min_ind][j];
            }
        }
    }
    int sum=0;
    for(int i=0;i<V;i++)
    {
        sum+=dist[i];
    }
    
  return sum;
}

