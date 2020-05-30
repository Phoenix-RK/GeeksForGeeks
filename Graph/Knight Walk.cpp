//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/knight-walk/0

Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.

*/


#include<bits/stdc++.h>
using namespace std;
#define N 25
#define M 25

void dfs(vector<vector<int>>&vis,int i,int j,int s1,int s2,int d1,int d2,int count,int& mini)
{
    if(s1<1 || s1>i || s2<1 || s2>j || vis[s1][s2]<=count) //boundary condition and checking if this particular vertex can be reached by anything with fewer steps ...if so break
        return;
    
    vis[s1][s2]=count; //vis stores the min no of steps to reach this particular point
    
    if(s1==d1 && s2==d2)
    {
        mini=min(count,mini);
        return;
    }
    
    dfs(vis,i,j,s1-1,s2-2,d1,d2,count+1,mini);
    dfs(vis,i,j,s1-1,s2+2,d1,d2,count+1,mini);
    
    dfs(vis,i,j,s1+1,s2-2,d1,d2,count+1,mini);
    dfs(vis,i,j,s1+1,s2+2,d1,d2,count+1,mini);
    
    dfs(vis,i,j,s1+2,s2+1,d1,d2,count+1,mini);
    dfs(vis,i,j,s1-2,s2+1,d1,d2,count+1,mini);
    
    dfs(vis,i,j,s1+2,s2-1,d1,d2,count+1,mini);
    dfs(vis,i,j,s1-2,s2-1,d1,d2,count+1,mini);
    
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
	    cin>>i>>j;
	    cin>>s1>>s2>>d1>>d2;
	    vector<vector<int>> vis(i+1,vector<int>(j+1,INT_MAX)); 
	    
	    dfs(vis,i,j,s1,s2,d1,d2,count,mini);
	    
	    if(mini==INT_MAX)
	        cout<<"-1"<<endl;
	    else
	        cout<<mini<<endl;
	    
	    
	}
	return 0;
}
