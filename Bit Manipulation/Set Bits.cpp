//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/set-bits0143/1#

Given a positive integer N, print count of set bits in it. 

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.
Example 2:

Input:
8
Output:
1
Explanation:
Binary representation is '1000' 
So the count of the set bit is 1.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 109

*/


class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        
        int count=0;
        while(N)
        {
            if(N&1)
                count++;
            N=N>>1;
        }
        return count;
    }
};





class Solution
{
public:
    int setBits(int N)
    {
        // Write Your Code here
        
        int count=0;
        while(N)
        {
           N=N&(N-1);
           count++;
        }
        return count;
    }
};

/*


1111
0111
-----
0111
0110
----
0110
0101
----
0100
0011
----
0000

*/
