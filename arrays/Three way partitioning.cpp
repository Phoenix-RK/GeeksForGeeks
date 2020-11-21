//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#


Given an array of size N and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.


Example 1:

Input: 
N = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input: N = 3 
A[] = {1, 2, 3}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement 
is: {1, 2, 3}. If you return a valid
arrangement, output will be 1.


Your Task:
You dont need to read input or print anything. The task is to complete the function threeWayPartition() which takes the array[], a and b as input parameters and modifies the array in-place according to the given conditions.
Note: The generated output is 1 if you modify the given array successfully.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
1 <= N <= 105
1 <= A[i] <= 106


*/


//User function template for C++

class Solution{   
public:
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int low=0,mid=0,high=array.size()-1;
        int i=0;
        
        
        while(mid<=high)
        {
            if(array[i]<a)
            {
                swap(array[i],array[low]);
                low++;
                mid++;
                i++;
            }
            else if(array[i]>b)
            {
                swap(array[i],array[high]);
                high--;
            }
            else
            {
                mid++;
                i++;
            }
    
        }

        
    }
};


