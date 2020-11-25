//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#

You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
Example 2:

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), 
the total number of set bits is 35.

Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106

*/


//User function Template for C++

// Function to count set bits in the given number x
// n: input to count the number of set bits

/*
int countSetBits(int n)
{
    if(n==0)
        return 0;
        
    int x=(log2(n));
    return((pow(2,x-1)*x) + (n-pow(2,x)+1) + countSetBits(n-pow(2,x)));

}

1 0 0  
0 1 1
0 1 0
0 0 1

=5


x=2

pow(2,1)*2 = 4
n-pow(2,2)+1 = 4-4+1 =1

*/





/*
0 0 0 1
0 0 1 0
0 0 1 1
0 1 0 0
0 1 0 1
0 1 1 0
0 1 1 1
1 1 1 1


x/2 =y

if(x is odd)
then the lsb is set =>  dividing by 2(right shifting) will make the lsb lost.
Hence, y will have one setbit less than x

else if(x is even)
then lsb wont be set => diving wont make the set bit lost
hence, y will have same no of setbits as x
*/


int countSetBits(int n)
{
    // Your logic here
    int set[n+1];
    set[0]=0;
    int count=0;
    for(int i=1;i<=n;i++)
    {
            set[i]=set[i/2]+(i%2);
            count+=set[i];
    }
    return count;
}


//O(n)
/*
int set_count(int x)
{
    int count=0;
    
    while(x)
    {
        x=x&(x-1);
            count++;
    }
    return count;
}
int countSetBits(int n)
{
    // Your logic here
    int count=0;
    for(int i=1;i<=n;i++)
    {
        count+=set_count(i);
    }
    return count;
}
*/
