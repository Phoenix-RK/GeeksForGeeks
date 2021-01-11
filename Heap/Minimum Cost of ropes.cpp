//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Example 1:

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 
29
Explanation:
For example if we are given 4
ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.\
1) First connect ropes of lengths 2 and 3.
Now we have three ropes of lengths 4, 6
and 5.
2) Now connect ropes of lengths 4 and 5.
Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all
ropes have connected.
Total cost for connecting all ropes is 5
+ 9 + 15 = 29. This is the optimized cost
for connecting ropes. Other ways of
connecting ropes would always have same
or more cost. For example, if we connect
4 and 6 first (we get three strings of 3,
2 and 10), then connect 10 and 3 (we get
two strings of 13 and 2). Finally we
connect 13 and 2. Total cost in this way
is 10 + 13 + 15 = 38.
Example 2:

Input:
n = 5
arr[] = {4, 2, 7, 6, 9}
Output: 
62
Your Task:
You are required to complete the method minCost() which takes 2 arguments and returns the minimum cost.

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ N ≤ 100000
1 ≤ arr[i] ≤ 106

*/




/*
{4, 2, 7, 6, 9}

2 4 6 7 9

count= 2+4 = 6  

6 6 7 9 

count = 6 +(6+6) = 18

12 7 9 

count = 18+(7+9) = 34

12 16

count = 34 + (12+16) = 62
*/

long long minCost(long long arr[], long long n) {
    // Your code here
    
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    
    for(long long i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    long long cost=0;
    while(pq.size()>=2)
    {
        long long x=pq.top();
        pq.pop();
        long long y=pq.top();
        pq.pop();
        
        cost+=x+y;
        pq.push(x+y);
    }
    
    return cost;
    
}
