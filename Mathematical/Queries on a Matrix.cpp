//Phoenix_RK
/*
You are given a matrix M of dimension N*N. All the cells are initially, zero. 
You are given Q queries, which contains 4 integers 
a b c d.
where (a,b) is the TOP LEFT cell and (c,d) is the Bottom Right cell of a submatrix.
Now, all the cells of This submatrix has to be incremented by one.
After all the Q queries have been performed. Your task is to print the final resulting Matrix.


1
6 6
4 0 5 3
0 0 3 4
1 2 1 2
1 1 2 3
0 0 3 1
1 0 2 4
Output:
2 2 1 1 1 0 
3 4 4 3 2 0 
3 4 3 3 2 0 
2 2 1 1 1 0 
1 1 1 1 0 0 
1 1 1 1 0 0

***********************************
use Difference array
***********************************
*/

#include<bits/stdc++.h>
using namespace std;


int main()
 {
	//code
	 int T,m,n;
 int a[101][101];
	cin>>T;
	while(T--)
	{
	    memset(a,0,sizeof(a));
	    cin>>m>>n;
	    int r1,r2,c1,c2;
	    while(n--)
	    {
	        cin>>r1>>c1>>r2>>c2;
	        a[r1][c1]++;
	        a[r1][c2+1]--;
	        a[r2+1][c1]--;
	        a[r2+1][c2+1]++;
	        
	    }
	     for(int i=1;i<m;i++)
	    {
	       a[i][0]+=a[i-1][0];
	        a[0][i]+=a[0][i-1];
	    }
	   
	   
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	           if(i!=0 && j!=0)
	            a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	            
	            cout<<a[i][j]<<" ";
	            
	        }
	        cout<<endl;
	    }
	   
	}
	return 0;
}

