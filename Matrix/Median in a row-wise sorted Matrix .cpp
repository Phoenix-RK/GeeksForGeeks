//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1<= R,C <=150
1<= matrix[i][j] <=1000



*/


//User function template for C++

class Solution{   
public:
 
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here     
        
            int min = INT_MAX;
            int max = INT_MIN;
            int req_count = (1+(r*c)/2);
           for(int i=0;i<r;i++)
            {
                if(matrix[i][0]<min)
                    min = matrix[i][0];
                if(matrix[i][c-1]>max)
                    max = matrix[i][c-1];
            }
            
            int count =0;
            while(min<max)
            {
           //     cout<<min<<" "<<max<<endl;
                count=0;
                int mid = (max+min)/2;
                for(int i= 0;i<r;i++)
                {
                    count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) -  matrix[i].begin();
                }
                if(count < req_count)
                    min = mid+1;
                else
                    max = mid;
                
            //    cout<<"e-"<<min<<" e-"<<max<<endl;
                
            }
            return min;
    }

    
};

