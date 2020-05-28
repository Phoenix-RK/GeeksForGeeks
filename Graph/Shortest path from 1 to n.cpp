//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0

Consider a directed graph whose vertices are numbered from 1 to n. There is an edge from a vertex i to a vertex j iff either j = i + 1 or j = 3i. The task is to find the minimum number of edges in a path in G from vertex 1 to vertex n.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int res=0;
	    while(n>1)
	    {
    	    while(n%3==0 && n>1)
    	    {
    	        n=n/3;
    	        res++;
    	    }
    	    
            while(n%3!=0 && n>1)
            {
                n--;
                res++;
            }
            
        }
	    cout<<res<<endl;
	    
	}
	return 0;
}
