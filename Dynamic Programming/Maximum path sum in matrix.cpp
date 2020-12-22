//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#


Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
â€‹Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.


Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function maximumPath() which takes the size N and the Matrix as input parameters and returns the highest maximum path sum.


Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N*N)


Constraints:
1 ≤ N ≤ 100
1 ≤ Matrix[i][j] ≤ 1000
*/



// User function Template for C++
  
class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
        vector<vector<int>> path(N,vector<int>(N,0));
        int max_val=INT_MIN;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int up_right=(i==0 || j==N-1)?0: path[i-1][j+1];
                int up_left =(i==0 || j==0)? 0 : path[i-1][j-1];
                int up      =(i==0)? 0: path[i-1][j];
                path[i][j]=Matrix[i][j]+max(up,max(up_right,up_left)); 
                
                if(i==N-1)
                    max_val=max(path[i][j],max_val);
            }
        }
        return max_val;
    }
};


