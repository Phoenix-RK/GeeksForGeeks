//Phoenix_RK
/*

Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.

4 3
1 0 0
1 0 0
1 0 0
0 0 0

1 1 1
1 1 1
1 1 1
1 0 0


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
	    int n,m,x;
	    cin>>n>>m;
	    
	  int row[n];
	  int col[m];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	            {
	                cin>>x;
	                if(x==1)
	                {
	                    row[i]=1;
	                    col[j]=1;
	                }
	            }
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(row[i]==1||col[j]==1)
	            cout<<"1"<<" ";
	            else
	            cout<<"0 ";
	        }
	        cout<<endl;
	    }
	    
	}
	return 0;
}
