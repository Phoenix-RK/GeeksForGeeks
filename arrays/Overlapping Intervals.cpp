//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/overlapping-intervals4919/1#

Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

Example 1:

Input:
N = 4
Intervals = {(1,3),(2,4),(6,8),(9,10)}
Output: 1 4 6 8 9 10
Explanation: Given intervals: [1,3],[2,4]
[6,8],[9,10], we have only two overlapping
intervals here,[1,3] and [2,4]. Therefore
we will merge these two and return [1,4],
[6,8], [9,10].
Example 2:

Input:
N = 4
Intervals = {(6,8),(1,9),(2,4),(4,7)}
Output: 1 9
Your Task:
Complete the function overlappedInterval() that takes the list of pairs and N as input parameters and returns sorted list of pairs of intervals after merging.

Expected Time Complexity: O(N*Log(N) ).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 100
0 ≤ x ≤ y ≤ 1000

*/


//User function template for C++

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    //code here
    
        if(n<=1)
            return vec;
        
        sort(vec.begin(),vec.end());

        vector<pair<int,int>> result;
        
        result.push_back(vec[0]);
     
        for(int i=1; i<n; i++)
        {
            if(result.back().second>=vec[i].first)
                result.back().second= max(result.back().second,vec[i].second);
            else
                result.push_back(vec[i]);           
        }
        
        return result;
    
}
