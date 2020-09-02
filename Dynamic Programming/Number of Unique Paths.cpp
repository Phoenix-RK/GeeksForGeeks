//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0

Given a M X N matrix with your initial position at the top-left cell, find the number of possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Input:
The first line contains an integer T, depicting the total number of test cases. Then following T lines contain two integers M and N depicting the size of the grid.

Output:
Print the number of unique paths to reach the bottom-right cell from the top-left cell.

Expected Time Complexity: O(M*N).
Expected Auxiliary Space: O(M*N).

Constraints:
1 ≤ T ≤ 30
1 ≤ M ≤ 20
1 ≤ N ≤ 20

Example:
Input:
2
2 2
3 4

Output:
2
10

Example:
Testcase 1:
There are only two unique paths to reach the end of the matrix of size two from the starting cell of the matrix.

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
	    int m,n;
	    cin>>m>>n;
	    int a[m][n];
	    
	    for(int i=0;i<m;i++)
	        a[i][0]=1;
	   for(int i=0;i<n;i++)
	        a[0][i]=1;
	   
	    for(int i=1;i<m;i++)
	    {
	        for(int j=1;j<n;j++)
	        {
	            a[i][j]=a[i-1][j]+a[i][j-1];
	        }
	    }
	  /*  for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	            cout<<a[i][j]<<" ";
	       cout<<endl;
	    }
	    */cout<<a[m-1][n-1]<<endl;
	}
	return 0;
}
