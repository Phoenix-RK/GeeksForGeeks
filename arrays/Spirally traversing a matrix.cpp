//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix/0


Given a matrix mat[][] of size M*N. Traverse and print the matrix in spiral form.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test cases follow. Each testcase has 2 lines. First line contains M and N respectively separated by a space. Second line contains M*N values separated by spaces.

Output:
Elements when travelled in Spiral form, will be displayed in a single line.

Constraints:
1 <= T <= 100
2 <= M,N <= 10
0 <= Ai <= 100

Example:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7



*/



//Phoenix_RK
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
    	{
    	    for(int j=0;j<n;j++)
    	        cin>>a[i][j];
    	}
    	
    	  int first_row=0,first_col=0,last_row=m-1,last_col=n-1;
    
        while(first_row<=last_row && first_col<=last_col)
        {
            for(int i=first_col;i<=last_col;i++)
                cout<<a[first_row][i]<<" ";
            
            first_row++;
            
            for(int i=first_row;i<=last_row;i++)
                cout<<a[i][last_col]<<" ";
                
            last_col--;
            
            if(first_row<=last_row)
            {
                for(int i=last_col;i>=first_col;i--)
                    cout<<a[last_row][i]<<" ";
                    
                last_row--;
            }
            
            if(first_col<=last_col)
            {
                for(int i=last_row;i>=first_row;i--)
                    cout<<a[i][first_col]<<" ";
                
                first_col++;
                
            }
        }
    	cout<<endl;
	
	}
	return 0;
}
