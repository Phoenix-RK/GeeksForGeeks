//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/find-whether-path-exist/0



iven a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

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
	    int mat[n][n],visited[n][n];
	    int sr,sc,dr,dc;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>mat[i][j];
	            visited[i][j]=0;
	            if(mat[i][j]==1)
	            {
	                sr=i;
	                sc=j;
	            }
	            else if(mat[i][j]==2)
	            {
	                dr=i;
	                dc=j;
	            }
	        }
	    }
	   int dir1[]={-1,1,0,0};
	   int dir2[]={0,0,-1,1};
	    
	    queue<pair<int,int>> q;
	    q.push(make_pair(sr,sc));
	    visited[sr][sc]=1;
	    while(!q.empty())
	    {
	        int r=q.front().first;
	        int c=q.front().second;
	        q.pop();
    	    for(int i=0;i<4;i++)
    	    {
    	        int rr=r+dir1[i];
    	        int cc=c+dir2[i];
    	        
    	        if(rr<0 || cc<0 || rr>n-1 ||cc>n-1)
    	        continue;
    	        
    	        if(mat[rr][cc] && !visited[rr][cc])
    	       {
    	           visited[rr][cc]=1;
    	           q.push(make_pair(rr,cc));
    	       }
    	    }

        }
        cout<<visited[dr][dc]<<endl;
	}
	return 0;
}


/****************************************************************************/



//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
#define MAX 21
int a[MAX][MAX];
bool vis[MAX][MAX];

bool search(int s1,int s2,int d1,int d2,int a[MAX][MAX],int n,bool vis[MAX][MAX])
{
    if(s1<0 || s2>=n || a[s1][s2]==0 || vis[s1][s2]==true)
        return  false;
        
    if(a[s1][s2]==2)
        return true;
        
    vis[s1][s2]=true;
    if(search(s1,s2+1,d1,d2,a,n,vis) || search(s1,s2-1,d1,d2,a,n,vis) || search(s1+1,s2,d1,d2,a,n,vis) || search(s1-1,s2,d1,d2,a,n,vis))
        return true;
        
    return false;
    
}


int main()
 {
	//code
	int T,n;
	cin>>T;
	while(T--)
	{
    	cin>>n;
    	int s1,s2,d1,d2;
    	
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=0;j<n;j++)
    	   {
    	       cin>>a[i][j];
    	       if(a[i][j]==1)
    	       {
    	           s1=i;
    	           s2=j;
    	       }
    	       else if(a[i][j]==2)
    	       {
    	           d1=i;
    	           d2=j;
    	       }
    	   }
    	}
   
    	memset(vis,false,sizeof(vis));
    	if(search(s1,s2,d1,d2,a,n,vis))
    	    cout<<"1"<<endl;
    	else
	        cout<<"0"<<endl;
	}
	return 0;
}
