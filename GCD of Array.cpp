//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/gcd-of-array/0

Given an array of N positive integers. Your task is to find the GCD of all numbers of the array.

Input:
First line of input contains number of test cases T. First line of test case contains a positive integer N, size of the array. Next line contains the array elements.

Output:
For each testcase, print the GCD of array elements.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= Arr[i] <= 106

Example:
Input:
1
2
5 10

Output:
5



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
    return gcd_ret(b,a%b);
}
int main()
 {
	//code
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n;
    	cin>>n;
    	ll a[n];
    	for(ll i=0;i<n;i++)
    	   cin>>a[i];
    	ll ans=a[0];
    	for(ll i=1;i<n;i++)
    	{
    	    ans=gcd_ret(ans,a[i]);
    	}
    	
    	cout<<ans<<endl;
    	
	
	}
	return 0;
}
