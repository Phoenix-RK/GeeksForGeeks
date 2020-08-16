//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/unsorted-array/0

Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Testcase 1 : Elements on left of 5 are smaller than 5 and on right of it are greater than 5.



*/


//Phoenix_RK
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
    	
    	int flag1=0,flag2=0; 
    	
    	for(int i=1;i<n-1;i++)
    	{
    	    flag1=0;
    	    flag2=0;
    	    for(int j=0;j<i;j++)
    	    {
    	        if(a[j]>a[i])
    	       {
    	           flag1=1;
    	           break;
    	       }
    	    }
    	    if(flag1==1)
    	        continue;
    	    
    	    for(int j=i+1;j<n;j++)
    	    {
    	        if(a[j]<a[i])
    	        {
    	            flag2=1;
    	            break;
    	        }
    	    }
    	    
    	    if(flag2==1)
    	        continue;
    	        
    	   if(flag1==0 && flag2==0)
    	   {
    	       flag1=-2;
    	       cout<<a[i]<<endl;
    	       break;
    	   }
    	}
    	
    	if(flag1!=-2)
    	    cout<<"-1"<<endl;
	
	}
	return 0;
}
