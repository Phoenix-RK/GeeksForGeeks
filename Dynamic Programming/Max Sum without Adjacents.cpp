//Phoenix_RK
/*
https://www.youtube.com/watch?v=UtGtF6nc35g

https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents/0

Given an array A of positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence should be adjacent in the array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, size of array. The second line of each test case contains N elements.

Output:
Print the maximum sum of a subsequence.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ci ≤ 107

Example:
Input:
2
6
5 5 10 100 10 5
4
3 2 7 10

Output:
110
13

Explanation:
Testcase 2 : 3 and 10 forms a non-continuous subsequence with maximum sum.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	    cin>>a[i];
	    int inc=0; //keeps track of maximum sum we could get at that time by including that element.Therefore, whenever we are updating inc, the maximum(old inc, exc+a[i]) is taken
	    int exc=0;//keeps track of maximum sum we could get at that time by including that element...the old inclusive becomes new exclusive because the old inclusive holds the max_so_far by excluding that particular element
	    
	    for(int i=0;i<n;i++)
	    {
	        int temp=inc;
	        inc=max(exc+a[i],inc);
	        exc=temp;
	    }
	    
	    cout<<max(inc,exc)<<endl;
	}
	return 0;
}
