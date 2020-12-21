//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#


Subset Sum Problem 
Medium Accuracy: 38.0% Submissions: 15318 Points: 4
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explaination: 
The two parts are {1, 5, 5} and {11}.

Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explaination: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000

*/



// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        
        int sum=0;
        
        for(int i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2)
            return 0;
        else
            sum/=2;
        
        bool dp[N+1][sum+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=N;i++)
            dp[i][0]=1;
            
        for(int i=1;i<=sum;i++)
            dp[0][i]=0;
            
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j<arr[i-1])
                    continue;
                else
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            
        }
       

        return dp[N][sum];
    }
};
