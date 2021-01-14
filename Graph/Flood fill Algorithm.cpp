//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1#


Given an image of size n*m, location of a pixel in the screen i,e(sr, cc) and color newColor, your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color newColor.
 

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.
 

Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
 

Constraints:
1 <= n <= m <= 100
0 <= pixel values <= 10
*/



class Solution {
public:
    
    void fill(vector<vector<int>>& image, int sr, int sc,int color, int newColor)
    {
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=color)
            return ;
            
        image[sr][sc]=newColor;
        fill(image,sr+1,sc,color,newColor);
        fill(image,sr-1,sc,color,newColor);
        fill(image,sr,sc+1,color,newColor);
        fill(image,sr,sc-1,color,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        if(image[sr][sc]==newColor)
            return image;
        
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
        
    }
};


