//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0


Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.

Input:
The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. Each test case consists of three lines. The first line of each test case contains an integer N denoting the number of packets. Then next line contains N space separated values of the array A denoting the values of each packet. The third line of each test case contains an integer m denoting the no of students.

Output:
For each test case in a new line print the minimum difference.

Constraints:
1 <= T <= 100
1 <=N<= 107
1 <= Ai <= 1018
1 <= M <= N

Example:
Input:
2
8
3 4 1 9 56 7 9 12
5
7
7 3 2 4 9 12 56
3

Output:
6
2

Explanation:
Testcase 1: The minimum difference between maximum chocolates and minimum chocolates is 9-3=6








*/

#include<bits/stdc++.h>
using namespace std;

int min(int a,int b)
{
    return a<b?a:b;
}

void merge(int a[],int l,int m,int r)
{
    
    int n1=m-l+1;
    int n2=r-m;
    
    int L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    
    for(int i=0;i<n2;i++)
        R[i]=a[m+1+i];
        

    int i=0,j=0,k=l;
    
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
        int m=l + (r-l)/2;
        
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
	    int n,k,diff=INT_MAX;
    	cin>>n;
    	
    	int a[n];
    	for(int i=0;i<n;i++)
    	    cin>>a[i];
	    cin>>k;
	    
	    sort(a,0,n-1);
	 /* 
	  for(int i=0;i<n;i++)
	        cout<<a[i]<<" ";
	       
	      cout<<endl;
*/
	    for(int i=0;i+k-1<n;i++)
	    {
	       // cout<<a[i]<<" "<<a[i+k-1]<<endl;
	        diff = min(diff,a[i+k-1]-a[i]);
	    }
	    
	    cout<<diff<<endl;
	}
	return 0;
}
