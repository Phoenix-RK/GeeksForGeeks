//Phoenix_RK


/*

Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] - mat[1][0] = 18 has maximum difference. 

*/



#include <bits/stdc++.h> 
using namespace std; 
  
int findMaxValue(int mat[][N]) 
{ 
   //the req maxvalue is calc as mat(c,d)-mat(a,b) such that c>a and d>b. Therefore the current cell val (mat[i][j]) must be subtracted from the largest value in the submatrix mat(i+1,j+1,N,N). This is largest value is calculated and stored in maxArr matrix
    int max_so_far = INT_MIN; 
    int maxArr[N][N]; //each cell(i,j) stores the largest element in the submatrix(i+1,j+1,N,N)
  
    maxArr[N-1][N-1] = mat[N-1][N-1]; 
  
    //set last row n last col
    int maxv = mat[N-1][N-1];
    for (int j = N - 2; j >= 0; j--) 
    { 
        if (mat[N-1][j] > maxv) 
            maxv = mat[N - 1][j]; 
        maxArr[N-1][j] = maxv; 
    } 
  
    maxv = mat[N - 1][N - 1];  
    for (int i = N - 2; i >= 0; i--) 
    { 
        if (mat[i][N - 1] > maxv) 
            maxv = mat[i][N - 1]; 
        maxArr[i][N - 1] = maxv; 
    } 
  
    for (int i = N-2; i >= 0; i--) 
    { 
        for (int j = N-2; j >= 0; j--) 
        { 
            if (maxArr[i+1][j+1] - mat[i][j] > max_so_far) 
                max_so_far = maxArr[i + 1][j + 1] - mat[i][j]; 
  
            maxArr[i][j] = max(mat[i][j], max(maxArr[i][j + 1],maxArr[i + 1][j]) ); 
        } 
    } 
  
    return maxValue; 
} 
  
// Driver program to test above function 
int main() 
{ 
   
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int mat[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>mat[i][j];
		}
		
		cout<<findMaxValue(mat)<<endl; 
  


	}       
    return 0; 
} 
