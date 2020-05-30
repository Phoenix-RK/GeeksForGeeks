//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/rotten-oranges/0

Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

*************************************************************

Do BFS

*/

#include<bits/stdc++.h>
using namespace std;
int m,n;
bool isvalid(int x,int y)
{
    if(x<0 || x>=m || y<0 || y>=n)
        return false;
    return true;
}
bool checkall(vector<vector<int>> a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j]==1)
                return false;
        }
    }
    return true;
}
int rotten(vector<vector<int>> a)
{
    int count=0;
    queue<pair<int,int>> q;
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j]==2)
            q.push(make_pair(i,j));
        }
    }
    
    while(!q.empty())
    {
        bool flag=false;
        int s=q.size();
        while(s>0)
        {
            
           pair<int,int> m=q.front();
           int x=m.first;
           int y=m.second;
       
       
           if(isvalid(x-1,y) && a[x-1][y]==1)
           {
               if(!flag)
                flag=true;
               
               a[x-1][y]=2;
               
               q.push(make_pair(x-1,y));
           }
            
           if(isvalid(x,y-1) && a[x][y-1]==1)
           {
               if(!flag)
                flag=true;
               
               a[x][y-1]=2;
               
               q.push(make_pair(x,y-1));
           }
           
           if(isvalid(x,y+1) && a[x][y+1]==1)
           {
               if(!flag)
                flag=true;
               
               a[x][y+1]=2;
               
               q.push(make_pair(x,y+1));
           }
           
           if(isvalid(x+1,y) && a[x+1][y]==1)
           {
               if(!flag)
                flag=true;
               
               a[x+1][y]=2;
               
               q.push(make_pair(x+1,y));
           }
          s--;
          q.pop();
        }
                
        if(flag)
            count++;
    }
    
  if(checkall(a))
    return count;
  else 
   return -1;
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    
	    cin>>m>>n;
	    
	    vector<vector<int>> a;
	    int temp;
	    
	    for(int i=0;i<m;i++)
	    {
	        vector<int> b;
	        for(int j=0;j<n;j++)
	        {
	            cin>>temp;
	            b.push_back(temp);
	        }
	        a.push_back(b);
	    }
	    
	    
	    
	    cout<<rotten(a)<<endl;
	}
	return 0;
	
}
