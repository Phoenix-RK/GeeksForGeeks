//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    
	    int ladder[31];//to store the steps to ladder
	    
	    for(int i=0;i<=30;i++)
	        ladder[i]=i;


	    int k,l;

	    for(int i=0;i<n;i++)
	    {
	        cin>>k>>l;
	        if(k<l)
	            ladder[k]=l;
	    }


	    int flag=0,count=0;
	    queue<pair<int,int>> q;
	    
	    bool *visited=new bool[31];
	    
	    for(int i=0;i<=30;i++)
	        visited[i]=false;
	    visited[1]=true;
	    q.push(make_pair(1,0));
	    
	    while(!q.empty())
	    {
	        pair<int,int> m=q.front();
	        int x=m.first;
	        int y=m.second;
	        
	        for(int i=1;i<=6;i++)//calculate for all possibilities in a dice
	        {
	            if(i+x<=30 && !visited[x+i])
	            { 
	                visited[ladder[x+i]]=true;  //if there is a ladder make that position as visited
	                q.push(make_pair(ladder[x+i],y+1));
			    
	    	            if(visited[30])
	    	            {
	    	                flag=1;
	    	                count=y+1;
	    	                break;
	    	            }
	            }
	        }
	        
	        q.pop();
	        if(flag)
	            break;
	    }
	    
	    cout<<count<<endl;
	}
	return 0;
}
