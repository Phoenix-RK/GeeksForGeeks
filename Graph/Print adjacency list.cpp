//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/print-adjacency-list/0

Given number of edges 'E' and vertices 'V' of a bidirectional graph. Your task is to build a graph through adjacency list and print the adjacency list for each vertex.

Input:
The first line of input is T denoting the number of testcases.Then first line of each of the T contains two positive integer V and E where 'V' is the number of vertex and 'E' is number of edges in graph. Next, 'E' line contains two positive numbers showing that there is an edge between these two vertex.

Output:
For each vertex, print their connected nodes in order you are pushing them inside the list . See the  given  example.

Constraints:
1 <= T <= 200
1 <= V <= 103
1 <= E = V*(V-1)

Example:
Input:
2
5 7
0 1
0 4
1 2
1 3
1 4
2 3
3 4
3 3
0 1
1 2
2 0

Output:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3
0-> 1-> 2
1-> 0-> 2
2-> 1-> 0

Explanation:
Testcase 1: Given graph has 5 nodes and 7 edges. After creating adjacency list of given graph, we have list as:
0-> 1-> 4
1-> 0-> 2-> 3-> 4
2-> 1-> 3
3-> 1-> 2-> 4
4-> 0-> 1-> 3
 

** For More Input/Output Examples Use 'Expected Output' option **
*/




#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,x,e1,e2;
    	cin>>n>>x;
    	vector<vector<int>> v(n);
    	
    	for(int i=0;i<x;i++)
    	{
    	    cin>>e1>>e2;
    	   
    	     v[e1].push_back(e2);
    	     v[e2].push_back(e1);
    	      
    	}
    	vector<int> :: iterator it;
    	int i,j;
    	for(i=0;i<n;i++)
    	{
    	    cout<<i;
    	    for(it = v[i].begin();it!=v[i].end();it++)
    	    {
    	        cout<<"-> "<<*it;
    	    }
    	    cout<<endl;
    	}
	
	}
	return 0;
}
