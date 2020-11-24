//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#


You are given an array A[] of size N. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
N = 6
A[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
N = 10
A[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array A and its size N as input parameters and returns the total number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(N)
 

Constraints:    
1<= N <= 107
-1010 <= Ai <= 1010

 */

//User function template for C++

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    //code here
    ll count=0;
    
    unordered_map<ll,ll> sum_map;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            count++;
        
        if(sum_map.find(sum)!=sum_map.end())
        {
            count+=sum_map[sum];
            sum_map[sum]+=1;
        }
        else
        {
            sum_map[sum]=1;
        }
    }
    return count;
}
