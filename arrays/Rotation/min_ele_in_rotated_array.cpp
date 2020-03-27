//Phoenix_RK
/*
A sorted array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

Expected Time Complexity: O(Log n)


Input
2
5
4 5 1 2 3
6
10 20 30 40 50 5 7

Output
1
5

*/


#include<bits/stdc++.h>
using namespace std;

int find_pivot(int *a,int low,int high)
{
    if(high<low)
        return 0;
    if(high==low)
        return low;
    int mid=(low+high)/2;
    if(low<mid && a[mid]<a[mid-1])
    return mid;
    else if(mid<high && a[mid]>a[mid+1])
    return mid+1;
    
    if(a[low]>=a[mid])
        return find_pivot(a,low,mid-1);
    
    return find_pivot(a,mid+1,high);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        
	   int pivot=find_pivot(a,0,n-1);
	   cout<<a[pivot]<<endl;
	}
	return 0;
}
