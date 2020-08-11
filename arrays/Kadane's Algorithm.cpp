//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print the maximum sum of the contiguous sub-array in a separate line for each test case.

Constraints:
1 ≤ T ≤ 110
1 ≤ N ≤ 106
-107 ≤ A[i] <= 107

Example:
Input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4
Output
9
-1

Explanation:
Testcase 1: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.



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
    	    
    	int max_so_far=a[0],curr_max=a[0];
    	
    	for(int i=1;i<n;i++)
    	{
    	    curr_max=max(a[i],curr_max+a[i]);
    	    max_so_far=max(curr_max,max_so_far);
    	}
    	cout<<max_so_far<<endl;
	}
	return 0;
}
