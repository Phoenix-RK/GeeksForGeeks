//Phoenix_RK

/*



https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

Your Task:
You dont need to read input or print anything. Complete the function spirallyTraverse() that takes matrix, R and C as input parameters and returns a list of integers denoting the spiral traversal of matrix. 

Expected Time Complexity: O(R*C)
Expected Auxiliary Space: O(1)

Constraints:
2 <= R, C <= 100
0 <= matrixi <= 100


*/


//Complete this function
void spirallyTraverse(int m, int n, int ar[SIZE][SIZE]){
    //Your code here
    
    int startrow=0,startcol=0,endrow=m-1,endcol=n-1;
while(startrow<=endrow && startcol <=endcol)
{

    for(int i=startcol;i<=endcol;i++)
    {
        cout<<ar[startrow][i]<<" ";
    }
    startrow++;
    
    for(int i=startrow;i<=endrow;i++)
    {
        cout<<ar[i][endcol]<<" ";
    }
    
    endcol--;
    
    if(startrow<=endrow)
    {
        for(int i=endcol;i>=startcol;i--)
            cout<<ar[endrow][i]<<" ";
        
        endrow--;
    
    }
    
    if(startcol<=endcol)
    {
        for(int i=endrow;i>=startrow;i--)
            cout<<ar[i][startcol]<<" ";
        
     startcol++;
    
    }
       
}
    
}
