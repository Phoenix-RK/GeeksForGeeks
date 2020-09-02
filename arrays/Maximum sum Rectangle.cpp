//Phoenix_RK

/*

https://www.youtube.com/watch?v=yCQN096CwWM

https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0

Given a 2D array, find the maximum sum subarray in it. 


Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29

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
	    int m,n;
    	cin>>m>>n;
    	int a[m][n];
    	
    	for(int i=0;i<m;i++)
    	{
    	    for(int j=0;j<n;j++)
    	        cin>>a[i][j];
    	}
    	int curr_sum=INT_MIN,max_so_far,curr_max;
    	int temp[m];
    	memset(temp,0,sizeof(temp));
    	for(int l=0;l<n;l++)
    	{
    	    for(int r=l;r<n;r++)
    	    {
    	        for(int i=0;i<m;i++)
        	    {
        	        temp[i]+=a[i][r];
        	    }
    	        
        	    max_so_far=temp[0],curr_max=temp[0];
    	
            	for(int i=1;i<m;i++)
            	{
            	    curr_max=max(temp[i],curr_max+temp[i]);
            	    max_so_far=max(curr_max,max_so_far);
            	}
    	        curr_sum=max(curr_sum,max_so_far);
    	    }
    	    
    	    memset(temp,0,sizeof(temp));
    	}
	    cout<<curr_sum<<endl;
	}
	return 0;
}
