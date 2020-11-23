//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#




Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).

Your Task:  
You don't need to read input or print anything. Your task is to complete the function rowWithMax1s() which takes the array of booleans arr[][], n and m as input parameters and returns the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.
 

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N, M ≤ 103
0 ≤ Arr[i][j] ≤ 1




*/

//User function template for C++
class Solution{
public:
int ind(vector<int> arr,int low,int high)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((mid==0 || arr[mid-1]==0) && arr[mid]==1)
        {
            return mid;
        }
        else if(arr[mid]==0)
            low=mid+1;
        else
            high=mid-1;
    }
    
    return -1;
}
int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
 {
	     
	     int row=-1,max=-1;
	     
	     for(int i=0;i<n;i++)
	     {
	         int x=ind(arr[i],0,m-1);
	         
	         if(x!=-1 && m-x>max)
	         {
	             max=m-x;
	             row=i;
	         }
	         
	         
	     }
	     
	     return row;
}
};
