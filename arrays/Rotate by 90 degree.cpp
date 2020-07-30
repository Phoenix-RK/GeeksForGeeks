//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/rotate-by-90-degree/0

Given a square matrix mat[][] of size N x N. The task is to rotate it by 90 degrees in anti-clockwise direction without using any extra space.

Example:
Input:
2
3
1 2 3 4 5 6 7 8 9
2
5 7 10 9
Output:
3 6 9 2 5 8 1 4 7
7 9 5 10

Explanation:
Testcase 1: Matrix is as below:
1 2 3
4 5 6
7 8 9

Rotating it by 90 degrees in anticlockwise directions will result as below matrix:
3 6 9
2 5 8
1 4 7



Idea:
Step1: Take transpose of the matrix
Step2: Reverse the elements within the columns (for anticlockwise)
    (transpose)  (reverse elements within the col)
1 2 3   1 4 7     3 6 9 
4 5 6   2 5 8     2 5 8
7 8 9   3 6 9     1 4 7

    (transpose)  (reverse elements within the row)
1 2 3  1 4 7      7 4 1
4 5 6  2 5 8      8 5 2
7 8 9  3 6 9      9 6 3
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
    	int a[n][n];
    	
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=0;j<n;j++)
    	        cin>>a[i][j];
    	}
    		
    	 for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp= a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp; 
            }
        }
        /*
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=0;j<n;j++)
    	        cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
        */
        
        for(int j=0;j<n;j++)
        {
            for(int i=0,k=n-1;i<k;i++,k--)
            {
                int temp=a[i][j];
                a[i][j]=a[k][j];
                a[k][j]=temp;
            }
        }
    	
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=0;j<n;j++)
    	        cout<<a[i][j]<<" ";
    	}
	    cout<<endl;
	}
	return 0;
}
