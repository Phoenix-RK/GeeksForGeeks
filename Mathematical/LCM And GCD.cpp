//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/lcm-and-gcd/0
Given two numbers A and B. The task is to find out their LCM and GCD.

Input:
The first line of input contains an integer T denoting the number of testcases. T testcases follow. In each test cases, there are two numbers A and B separated by space.

Output:
For each testcase in a new line, print LCM and GCD separated by space.

Constraints:
1 <= T <= 104
1 <= A <= 108
1 <= B <= 108

Example:
Input:
2
5 10
14 8

Output:
10 5
56 2

Explanation:
Testcase 1: LCM and GCD of given numbers 5 and 10 are: 10 and 5.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd_ret(ll a, ll b)
{
    if(a==0)
        return b;
    if(b==0)
        return a;
    return  gcd_ret(b,a%b); // works fine if a> b and b>a as well (it swaps such that greater no is always first)eg: 6,4 and 4,6
}
int main()
 {
	//code
	ll T;
	cin>>T;
	while(T--)
	{
	    ll m,n;
    	cin>>m>>n;
    	ll gcd = gcd_ret(m,n);
    	ll lcm = m*n /gcd;
    	cout<<lcm<<" "<<gcd<<endl;
	
	}
	return 0;
}
