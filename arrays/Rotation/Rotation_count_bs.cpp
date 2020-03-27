//Phoenix_RK
/*
Given a sorted array A of size N. The array is rotated 'K' times. Find the value of 'K'. The array may contain duplicate elements.


Input
2
5
5 1 2 3 4
5
1 2 3 4 5
Output
1
0
*/

#include<bits/stdc++.h>
using namespace std;
long int max(long int a,long int b)
{
    return a>b?a:b;
}
long int search_pivot(long int *a,long int low,long int high)
{
    if(high<=low)
        return 0;
   long int mid=(high+low)/2;
    if(high>mid && a[mid]>a[mid+1])
        return mid+1;
    else if(low<mid && a[mid]<a[mid-1])
        return mid;
    
    if(a[low]>a[mid])
        return search_pivot(a,low,mid);
    else if(a[low]<a[mid])
        return search_pivot(a,mid+1,high);
    else
        return max(search_pivot(a,low,mid),search_pivot(a,mid+1,high));
}



int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        long int n,d;
        cin>>n;
     long  int a[n];
        for(long int i=0;i<n;i++)
            cin>>a[i];
       
        long int pivot=search_pivot(a,0,n-1);
       
        cout<<pivot;
        
        cout<<endl;
    }
	return 0;
}
