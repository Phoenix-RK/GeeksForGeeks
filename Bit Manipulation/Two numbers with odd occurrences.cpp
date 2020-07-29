//Phoenix_RK
/*


Find the two numbers with odd occurrences in an unsorted array

https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences/0


Given an unsorted array arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which have odd occurrences.

Note: Expected O(n) time complexity and O(1) extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. Then the following line contains n space separated integers. 

Output:
Print two space separated integers which have odd occurrences. Print the greater number first and then the smaller odd number.

Constraints:
1 <= T <= 100
2 <= N <= 105
1 <= arr[i] <= 105

Example:
Input:
2
8
4 2 4 5 2 3 3 1
6
1 7 5 5 4 4

Output:
5 1
7 1

Explanation:
Testcase 1: 5 and 1 are odd occurring elements in the array.
Testcase 2: 7 and 1 are odd occurring elements in the array.


*/

//for explanation refer finding the numbers

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
    	
    	int XOR;
    	for(int i=0;i<n;i++)
            cin>>a[i];   
        
        XOR=a[0];
        
        for(int i=1;i<n;i++)   
    	    XOR=XOR^a[i];
    	    
    	 
    	int set_bit;
    	set_bit = XOR & ~(XOR-1);  
    	int x=0 , y=0;
    	
    	for(int i=0 ;i<n;i++)
    	{
    	    if(a[i] & set_bit )
    	     x = x^a[i];
    	    
	        else
    	     y = y^a[i];
    	}
        if(x>y)
    	cout<<x<<" "<<y<<endl;
	    else
	    cout<<y<<" "<<x<<endl;
	}
	return 0;
}
