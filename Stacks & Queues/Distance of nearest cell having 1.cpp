//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#


Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 

Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0 
1 1 0 0 
0 0 1 1 
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.
Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a 
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.
 

Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes grid as input parameter and returns a matrix of same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(1)
*/




class Solution {
public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    
	   vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),INT_MAX));
	   
	   if(grid.size()==0)
	        return ans;
	   queue<pair<int,int>> q;    
	   for(int i=0;i<grid.size();i++)
	   {
	       for(int j=0;j<grid[0].size();j++)
	       {
	           if(grid[i][j]==1)
	           {
	               ans[i][j]=0;
	               q.push({i,j});
	           }
	       }
	   }
	   
	   int x[4]={-1,1,0,0};
	   int y[4]={0,0,1,-1};
	  while(!q.empty())
	  {
	      pair<int,int> temp=q.front();
	      q.pop();
	      
	      for(int i=0;i<4;i++)
	      {
	          int x_temp = temp.first  + x[i];
	          int y_temp = temp.second + y[i];
	          
	          if(x_temp>=0 && x_temp<grid.size() && y_temp>=0 && y_temp<grid[0].size() && ans[x_temp][y_temp]> ans[temp.first][temp.second]+1)
	          {
	              ans[x_temp][y_temp]= ans[temp.first][temp.second]+1;
	              q.push({x_temp,y_temp});
	          }
	      }
	  }
	  return ans;
	}
};
