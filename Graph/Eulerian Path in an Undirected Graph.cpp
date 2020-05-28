//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
/*
concept for this question is :
for undirected graph
eulerian path should have either all node degree as even or exactly two node having degree odd.

for directed graph
1) indegree==outdegree
2) abs(indegree-outdegree) either 0 or 1
3) at most one vertex having
indegree-outdegree=1
outdegree-indegree=1

*/

int main()
 {
	//code
	int T,n;
	cin>>T;
	
	while(T--)
	{
	    
	   cin>>n;

       vector<vector<int>> a(n);
       
	   for(int i=0;i<n;i++)
	   {
	       a[i]= vector<int>(n);
	       
	       for(int j=0;j<n;j++)
	       {
	           cin>>a[i][j];
	       }
	   }
	   
	   
	   
	int count[n],odd=0,even=0;
  
    for(int i=0;i<n;i++)
    {
        count[i]=0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==1)
                count[i]++;
           
        }
        
        if(count[i]%2==1)
            odd++;
        else 
            even++;
    }
    
	if(odd==2 ||odd==0)
       cout<<"1"<<endl;
    else
       cout<<"0"<<endl;

	  a.clear();
	}
	return 0;
}
