//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/find-optimum-operation/0

You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:

Double the number
Add one to the number
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the minimum number of operations required to reach N from 0.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
2
8
7
Input:
4
5

Explanation:
Testcase1:
Input  : N = 8
Output : 4
0 + 1 = 1, 1 + 1 = 2, 2 * 2 = 4, 4 * 2 = 8
Testcase2:
Input  : N = 7
Output : 5
0 + 1 = 1, 1 + 1 = 2, 1 + 2 = 3, 3 * 2 = 6, 6 + 1 = 7


**************************************************************
Idea: 

Any number is formed by element before it or doubling some element.
Hence we need to add 1 to the min of (no of ways in which an element one less than it is formed, the no of ways in which the ele/2 is formed)
*/



//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
	    int a[n+1];
	    a[0]=0;
	    for(int i=1;i<=n;i++)
	    {
	        if(i>2 && (i%2==0))
	            a[i]=1+min(a[i-1],a[i/2]);
	        else
	            a[i]=1+a[i-1];
	    }
	/*   
	   for(int i=0;i<=n;i++)
	    cout<<a[i]<<" ";
	  */
	   cout<<a[n]<<endl;
	}
	return 0;
}
