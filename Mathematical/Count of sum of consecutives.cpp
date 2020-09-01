//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/count-of-sum-of-consecutives/0


Given a number N, the task is find the number of ways to represent this number as a sum of 2 or more consecutive natural numbers.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N as input.

Output:
For each test case, print the total number of ways In new line. If the number can not be represent in the required way, print "0" without quotes.

Constraints:
1 <= T <= 6000
2 <= N <= 109

Example:
Input:
2
10
15
Output:
1
3


*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T;
	cin>>T;
	while(T--)
	{
	    long long int n;
        long long int count=0;
        float a;
        cin>>n;
   /* 	
    	       (l(l+1)
    	   N-  ------
    	           2
    	a=   -----------
    	        (L+1)
	*/
	
	   for(long long int l=1;(l*(l+1))<2*n;l++)
	   {
	       a= (1.0* n - ((l*(l+1))/2))/(l+1);
	       if(a-(long long int)a==0.0)
	          count++;
	   }
	   
	   cout<<count<<endl;
	}
	return 0;
}
