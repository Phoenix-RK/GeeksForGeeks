//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases. For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 107

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Testcase 1: Given array : 1 2 3 5. Missing element is 4.


*******************************
1)Find XOR of array elements
2)Find XOR of n elements
3)XOR of these gives the missing number (since it sets the bits fro which the bits are different)
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
	  
	    int n,x,exor_a=0,exor=0;
    	    cin>>n;
	    for(int i=0;i<n-1;i++)
	    {
	        cin>>x;
	        exor_a=exor_a^x;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        exor=exor^i;
	    }
	    exor_a=exor_a^exor;
	    cout<<exor_a<<endl;
	}
	return 0;
}
