//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#



Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists. If more than one such range's are found, find the first such range found.

Example 1:

Input:
N = 5, K = 3
KSortedArray[][] = {{1 3 5 7 9},
                    {0 2 4 6 8},
                    {2 3 5 7 11}}
Output: 1 2
Explanation: K = 3
A:[1 3 5 7 9]
B:[0 2 4 6 8]
C:[2 3 5 7 11]
Smallest range is formed by number 1
present in first list and 2 is present
in both 2nd and 3rd list.
Example 2:

Input:
N = 4, K = 3
KSortedArray[][] = {{1 2 3 4},
                    {5 6 7 8},
                    {9 10 11 12}}
Output: 4 9
Your Task :

Complete the function findSmallestRange() that receives array , array size n and k as parameters and returns the output range (as a pair<int,int> in cpp and array of size 2 in java and python)

Expected Time Complexity : O(n * k *log k)
Expected Auxilliary Space  : O(k)

*/




// you are required to complete this function 
// function should print the required range
#include<queue>
// you are required to complete this function 
// function should print the required range
typedef pair<int,pair<int,int>> pd;
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
      //code here
      //priority_queue<pd,vector<pd>,greater<pd>> pq;
      priority_queue<pd,vector<pd>,greater<pd>> pq;
      int max_ele=INT_MIN;
      int min_range=INT_MAX;
      pair<int,int> res;
      for(int i=0;i<k;i++)
      {
         if(arr[i][0]>max_ele)
            max_ele=arr[i][0];
        pq.push({arr[i][0],{i,0}});
      }
      
      
    while(!pq.empty())
    {
        pd curr=pq.top();
        pq.pop();
        
        if(max_ele - curr.first < min_range )
        {
            min_range=max_ele - curr.first ;
            res.first=curr.first;
            res.second=max_ele;
        }
        int row=curr.second.first;
        int col=curr.second.second;
        if(col+1>=n)
            break;
        if(arr[row][col+1]>max_ele)
            max_ele = arr[row][col+1];
        pq.push({arr[row][col+1],{row,col+1}});
    }
      return res;
}






