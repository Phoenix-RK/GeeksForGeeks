//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#



Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

Example 1:

Input:
9 3
1 2 3 1 4 5 2 3 6

Output: 
3 3 4 5 5 5 6 

Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
10 4
8 5 10 7 9 4 15 12 90 13

Output: 
10 10 10 15 15 90 90

Your Task:  
You dont need to read input or print anything. Complete the function max_of_subarrays() which takes the array, N and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 107
1 ≤ K ≤ N
0 ≤ arr[i] <= 107

*/





vector <int> max_of_subarrays(int *arr, int n, int k){
    // your code here
    
    deque<int> dq;
    vector<int> res;
    
    
    for(int i=0;i<n;i++)
    {
        if(!dq.empty() && i-k==dq.front())
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();
            
        dq.push_back(i);
        
        if(i>=k-1)
            res.push_back(arr[dq.front()]);
    }
    
    return res;
}



