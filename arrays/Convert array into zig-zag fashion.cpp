//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0

Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains a single integer N denoting the size of array.
The second line contains N space-separated integers denoting the elements of the array.

Output:
For each testcase, print the array in Zig-Zag fashion.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= Ai <= 10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3


**********************************************************

 a < b > c < d > e < f

the element at the even index must be less than its neighbouring elements.
if this is not met, then swap the elements.

*/

#include<bits/stdc++.h>
using namespace std;
void swap(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
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
    	int a[n];
    	

    	
    	for(int i=0;i<n;i++)
    	    cin>>a[i];
    	    
    	for(int i=0;i<n;i=i+2)
    	{
    	    if(i>0 && a[i]>a[i-1])
    	   {
    	        int temp=a[i];
                    a[i]=a[i-1];
                    a[i-1]=temp;
    	   }
    	    
    	    if(i<n-1 && a[i]>a[i+1])
    	    {
    	        int temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
    	    }
    	}
    	
    	for(int i=0;i<n;i++)
    	    cout<<a[i]<<" ";
    	    
    	cout<<endl;
    	
	
	}
	return 0;
}
