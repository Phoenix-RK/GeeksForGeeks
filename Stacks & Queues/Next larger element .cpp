//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/next-larger-element/0

Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test cases follow. Each test case consists of two lines. The first line contains an integer N denoting the size of the array. The Second line of each test case contains N space separated positive integers denoting the values/elements in the array A.

Output:
For each test case, print in a new line, the next greater element for each array element separated by space in order.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= Ai <= 1018
Example:
Input
2
4
1 3 2 4
4
4 3 2 1
Output
3 4 4 -1
-1 -1 -1 -1

Explanation:
Testcase1: In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist hence -1.



***************************************************
1)iterate for every element in the array
	->if the stack is not empty and the top of stack is less than a[i],then a[i] is the next greater element of s.top(). Therfore store that in a map
	->push the element into the stack if the stack is empty or s.top()>a[i]

2)if stack is not empty, it means that , no element is greter than the element present in the stack. Therfore, in map, for the keys in the stack store the values as -1;
*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
    	stack<ll> s;
    	map<ll,ll> m;
    	for(ll i=0;i<n;i++)
    	{
    	   cin>>a[i];
    	}
    /*	1 3 2 4
    	
    	stack 3 2
    	
    	
    	m[(1 3)]
    */	for(ll i=0;i<n;i++)
    	{
    	    
    	        while(!s.empty() && s.top()<a[i])
    	          {
    	                m[s.top()]=a[i];
    	                s.pop();
    	          }
    	              s.push(a[i]);
    	         
    	}
        while(!s.empty())
        {
            m[s.top()]=-1;
            s.pop();
        }
		for(ll i=0;i<n;i++)
    	{
    	   // if(m.find(a[i])!=m.end())
    	        cout<<m[a[i]]<<" ";
    	   //else
    	     //   cout<<"-1 ";
    	}
    	cout<<endl;
	
	}
	return 0;
}
