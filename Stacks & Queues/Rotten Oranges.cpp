//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1


Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).

*/



class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
       int steps=-1;
       int orange=0;
       queue<pair<int,int>> q; 
       for(int i=0;i<grid.size();i++)
       {
           for(int j=0;j<grid[0].size();j++)
           {
               if(grid[i][j]>0)
                  orange++;
               if(grid[i][j]==2)
                   q.push({i,j});
           }
       }
        
        int x[4]={0,0,-1,1};
        int y[4]={1,-1,0,0};
        
        while(!q.empty())
        {
            steps++;
            int s=q.size();
            
            while(s--)
            {
                pair<int,int> temp=q.front();
                q.pop();
                orange--;
                for(int i=0;i<4;i++)
                {
                    int x_temp = temp.first + x[i];
                    int y_temp = temp.second + y[i];
                    
                    if(x_temp>=0 && x_temp<grid.size() && y_temp>=0 && y_temp<grid[0].size() && grid[x_temp][y_temp]==1)
                    {
                              grid[x_temp][y_temp]=2;
                              q.push({x_temp,y_temp});                             
                    }
                }                
            }
        }
        
        if(orange==0)
            return max(0,steps);//if there are no oranges then steps would be -1 but actual ans should be 0
        return -1;
    }
};



