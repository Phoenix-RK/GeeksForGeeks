//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0#

Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: There is at least one subarray with sum greater than x

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers N and x. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required ouput.

Constraints:
1<=T<=100
1<=N,x<=1000
1<=A[]<=1000

Example:
Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7
Output:
3
1


*/



//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    
    
    while(T--)
    {
        int n,sum;
        cin>>n>>sum;
        int a[n];
        
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        int sum_arr=0,j=0,i=0,len=n+1;
        
        
        while(i<n)
        {
            while(i<n && sum_arr<=sum)
            {
                sum_arr+=a[i];
                i++;
            }
           
            while(sum_arr>sum && j<n)
            {
                if(i-j < len)
                    len= i-j;
                    
                sum_arr-=a[j];
                j++;
            }
        }
        
        cout<<len<<endl;
    }
    
    
    return 0;
}



