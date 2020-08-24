//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/n-queen-problem/0

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other. Given an integer n, print all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens’ placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the chessboard.

Output:
For each test case, output your solutions on one line where each solution is enclosed in square brackets '[', ']' separated by a space . The solutions are permutations of {1, 2, 3 …, n} in increasing order where the number in the ith place denotes the ith-column queen is placed in the row with that number, if no solution exists print -1.

Constraints:
1 <= T <= 10
1 <= n <= 10

Example:
Input
2
1
4
Output:
[1 ]
[2 4 1 3 ] [3 1 4 2 ]









*/


#include<bits/stdc++.h>
using namespace std;
int b[10][10];


void printsoln(int b[][10],int n)
{
    cout<<"[";
    
       
            for(int i=0;i<n;i++)
           {
             for(int j=0;j<n;j++)
             {
                if(b[i][j]==1)
                    cout<<j+1<<" ";
             }
           }
    cout<<"] ";
}
bool issafe(int b[][10],int row,int col,int n)
{
 
   
   for(int i=0;i<10;i++)
   {
       for(int j=0;j<10;j++)
       {
           if(i!=row && j!=col)
           if(b[row][j]==1 || b[i][col]==1 || (i-j ==row-col && b[i][j]==1) || (i+j ==col+row && b[i][j]==1))//1)same row 2)same col 3) 
              return false;
       }
   }
   return true;
}
bool solve(int b[][10],int row,int n)
{
    if(row==n)// if suppose the row has reached max it means one possible solution has been found for eg: n=4 and row =4 which means queen has been successfully placed in 0,1,2,3 rows.
    {
        printsoln(b,n);
        return true;
    }
    bool res=false;
    for(int j=0;j<n;j++)// for this particular row,check in which column the queen can be placed
    {
        if(issafe(b,row,j,n)) //if can be placed..
        {
            b[row][j]=1;
            res=solve(b,row+1,n)||res;//check if the other queens can be placed in subsequent rows without any problems
            b[row][j]=0;//else it means that placing queen at this position will affect others too..so take back and check for other columns in the same row
        }
    }
    return res;//placing queen on any col of the concerned row can be problemetic so return false..this will help in taking back previous queen's position
}
void solvenqueen(int n)
{
    
    memset(b,0,sizeof(b));
    if(solve(b,0,n)==false)//send the 0th row
    {
        cout<<"-1";
    }
    return;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
	    solvenqueen(n);
	    cout<<endl;
	}
	return 0;
}
