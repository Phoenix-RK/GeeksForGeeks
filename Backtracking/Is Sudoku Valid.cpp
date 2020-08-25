//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/is-sudoku-valid/0/

Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix (mat[][]) the task to check if the configuration has a solution or not. 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 9*9 space separated values of the matrix mat[][] representing an incomplete Sudoku state where a 0 represents empty block.

Output:
For each test case in a new line print 1 if the sudoku configuration is valid else print 0.

Constraints:
1<=T<=10
0<=mat[]<=9

Example:
Input:
2
3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0
3 6 7 5 3 5 6 2 9 1 2 7 0 9 3 6 0 6 2 6 1 8 7 9 2 0 2 3 7 5 9 2 2 8 9 7 3 6 1 2 9 3 1 9 4 7 8 4 5 0 3 6 1 0 6 3 2 0 6 1 5 5 4 7 6 5 6 9 3 7 4 5 2 5 4 7 4 4 3 0 7 

Output:
1
0
*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int mat[9][9];
bool unassigned(int mat[9][9],int &row,int &col)
{
    for(row=0;row<9;row++)
    {
        for(col=0;col<9;col++)
        {
            if(mat[row][col]==0)
                return true;
        }
    }
    
    return false;
}

bool inrow(int mat[9][9],int row,int val)
{
    for(int i=0;i<9;i++)
    {
        if(mat[row][i]==val)
            return true;
    }
    return false;
}


bool incol(int mat[9][9],int col,int val)
{
    for(int i=0;i<9;i++)
    {
        if(mat[i][col]==val)
            return true;
    }
    return false;
}


bool inbox(int mat[9][9],int srow,int scol,int val)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(mat[srow+i][scol+j]==val)
                return true;
        }
    }
    return false;
}


bool issafe(int mat[9][9],int row,int col,int val)
{
    return (!inrow(mat,row,val) && !incol(mat,col,val) && !inbox(mat,row-row%3,col-col%3,val) && mat[row][col]==0 );
}

bool solve(int mat[9][9])
{
    int row,col;
    
    if(!unassigned(mat,row,col))
        return true;
        
    for(int i=1;i<=9;i++)
    {
         if(issafe(mat,row,col,i))
         {
             mat[row][col]=i;
             if(solve(mat))
                return true;
             mat[row][col]=0;
         }
    }
    
    return false;
}


int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	            cin>>mat[i][j];
	    }
	    if(solve(mat))
	        cout<<"1"<<endl;
	    else
	        cout<<"0"<<endl;
	}
	return 0;
}
