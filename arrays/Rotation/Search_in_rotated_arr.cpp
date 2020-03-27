//Phoenix_RK
/*
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.

Example:
Input:
3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

Output:
5
1
-1


*/
#include<bits/stdc++.h>
using namespace std;

int bs(int *a,int low,int high,int key)
{
    if(high<low)
        return -1;
    
    int mid=(high+low)/2;
    
    if(a[mid]==key)
       return mid;
    else if(a[mid]<key)
        return bs(a,mid+1,high,key);
    else 
        return bs(a,low,mid-1,key);
    
}

int find_pivot(int *a,int low,int high)
{
    if(high<low)
        return -1;
    if(low==high)
        return low;
    int mid=(high+low)/2;  
    if(mid<high && a[mid+1]<a[mid])
        return mid;
    else if(mid>low && a[mid]<a[mid-1])
        return mid-1;
    
    if(a[low]>=a[mid])
        return find_pivot(a,low,mid-1);
    
    return find_pivot(a,mid+1,high);

}
int search(int *a,int n,int key)
{
    int pivot=find_pivot(a,0,n-1);
    if(pivot==-1)
        return bs(a,0,n-1,key);
    if(a[pivot]==key)
        return pivot;
    if(a[0]<=key)
        return bs(a,0,pivot-1,key);
    return bs(a,pivot+1,n-1,key);
    
    
}
int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int a[n],key;
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    cin>>key;
	    int ind=search(a,n,key);
	    cout<<ind<<endl;
	}
	return 0;
}
