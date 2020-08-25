//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1


Given a set of positive integers. The task is to complete the function maxSubarrayXOR which returns an integer denoting the maximum XOR subset value in the given set.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the size of the array A[]. Then in the next line are N space separated values of the array.

Output Format:
For each test case in a new line output will be the maximum XOR subset value in the given set.

Your Task:
You need to complete the function maxSubarrayXOR.

Constraints:
1 <= T <= 100
1 <= N <= 50

Example:
Input:
2
3
2 4 5
3
9 8 5
Output:
7
13

Explanation:
Testcase1:
Input: set[] = {2, 4, 5}
Output: 7
The subset {2, 5} has maximum XOR value
Testcase2:
Input: set[] = {9, 8, 5}
Output: 13
The subset {8, 5} has maximum XOR value


*/


#include<bits/stdc++.h>
using namespace std;
 
// Number of bits to represent int
#define INT_BITS 32
int maxSubarrayXOR(int [], int n);
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
      scanf("%d",&n);

        for(int i=0;i<n;i++)
            {
            scanf("%d",&a[i]);
            }


   
printf("%d\n",maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;


    }
}// } Driver Code Ends


int find(int A[],int n,int ind,int a)
{
    if(ind==n)
        return a;
     
    return max(find(A,n,ind+1,a^A[ind]),find(A,n,ind+1,a));
}

// Function to return maximum XOR subset in set[]
int maxSubarrayXOR(int A[], int n)
{
    //Your code here
   return find(A,n,0,0);
}
