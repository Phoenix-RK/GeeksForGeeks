//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/cutted-segments/0

Given an integer N denoting the Length of a line segment. you need to cut the line segment in such a way that the cut length of a line segment each time is integer either x , y or z. and after performing all cutting operation the total number of cutted segments must be maximum. 


Input
First line of input contains of an integer 'T' denoting number of test cases. First line of each testcase contains N . Second line of each testcase contains 3 space separated integers x , y and z.

Output
For each test case print in a new line an integer corresponding to the answer .


Constraints
1<=t<=70
1<=N,x,y,z<=4000
 

Example

Input

2
4
2 1 1
5
5 3 2


Output
4
2

In first test case, total length is 4, and cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1. In secon test case, we can make two segments of lengths 3 and 2.
*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    
    int n1=m-l+1;
    int n2=r-m;
    
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int i=0;i<n2;i++)
        R[i]=a[m+1+i];
        
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}
void sort(int a[],int l,int r)
{
    if(l<r)
    {
        int m= l+ (r-l)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        
        merge(a,l,m,r);
    }
    
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
    	int a[3];
    	for(int i=0;i<3;i++)
    	    cin>>a[i];
    	 sort(a,0,2);
    	 int x[4][n+1];
    	 for(int i=0;i<4;i++)
    	     x[i][0]=0;
    	 for(int j=0;j<=n;j++)
    	     x[0][j]=0;
    	 for(int i=1;i<4;i++)
    	 {
    	     for(int j=1;j<=n;j++)
    	     {
    	         if(i==1)
    	         {
    	            if(j%a[i-1]==0)
    	               x[i][j]=j/a[i-1];
    	            else 
    	               x[i][j]=0;
    	         }
    	        else
    	        {
        	        if(j<a[i-1])
    	                x[i][j]=x[i-1][j];
    	            else if(x[i-1][j]==0 && x[i][j-a[i-1]]==0 && j-a[i-1]!=0)
    	                x[i][j]=0;
    	            else
    	                x[i][j]=max(x[i-1][j],1+x[i][j-a[i-1]]);
    	        }    
	          
	         }
    	 }/*
    	 for(int i=0;i<4;i++)
    	 {
    	     for(int j=0;j<=n;j++)
    	        cout<<x[i][j]<<" ";
    	        
    	   cout<<endl;
    	 }
	 */   cout<<x[3][n]<<endl;
	}
	return 0;
}
