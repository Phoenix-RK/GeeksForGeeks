//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/steps-by-knight/0



Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.

*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&vis,int i,int s1,int s2,int d1,int d2,int count,int& mini)
{
    if(s1<1 || s1>i || s2<1 || s2>i || vis[s1][s2]<=count) //boundary condition and checking if this particular vertex can be reached by anything with fewer steps ...if so break
        return;
    
    vis[s1][s2]=count; //vis stores the min no of steps to reach this particular point
    
    if(s1==d1 && s2==d2)
    {
        mini=min(count,mini);
        return;
    }
    
    dfs(vis,i,s1-1,s2-2,d1,d2,count+1,mini);
    dfs(vis,i,s1-1,s2+2,d1,d2,count+1,mini);
    
    dfs(vis,i,s1+1,s2-2,d1,d2,count+1,mini);
    dfs(vis,i,s1+1,s2+2,d1,d2,count+1,mini);
    
    dfs(vis,i,s1+2,s2+1,d1,d2,count+1,mini);
    dfs(vis,i,s1-2,s2+1,d1,d2,count+1,mini);
    
    dfs(vis,i,s1+2,s2-1,d1,d2,count+1,mini);
    dfs(vis,i,s1-2,s2-1,d1,d2,count+1,mini);
    
    return;
    
}

int main()
 {
	//code
	int T,n;
	cin>>T;
	while(T--)
	{
	    int s1,s2,d1,d2,i,j;
	    int count=0,mini=INT_MAX;
	    cin>>i;
	    cin>>s1>>s2>>d1>>d2;
	    vector<vector<int>> vis(i+1,vector<int>(i+1,INT_MAX)); 
	    
	    dfs(vis,i,s1,s2,d1,d2,count,mini);
	    
	    if(mini==INT_MAX)
	        cout<<"-1"<<endl;
	    else
	        cout<<mini<<endl;
	    
	    
	}
	return 0;
}
