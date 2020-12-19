//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#


Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

Example 2: 

Input: N = 2
Output: 2
Explanation:
{1} , {2} : All single.
{1,2} : 1 and 2 are paired.

Your Task:
You don't need to read input or print anything. Your task is to complete the function countFriendsPairings() which accepts an integer n and return number of ways in which friends can remain single or can be paired up.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)



*/


#define N 1000000007

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        
        long long int a[n+1];
        memset(a,0,sizeof(a));
        a[1]=1;
        a[2]=2;
        for(int i=3;i<=n;i++)
            a[i]=((a[i-1])%N+ (((i-1)%N)*(a[i-2]%N)%N)%N)%N;
        
        return a[n];
    }
};    
 
