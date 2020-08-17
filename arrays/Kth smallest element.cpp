//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.

Input:
The first line of input contains an integer T, denoting the number of testcases. Then T test cases follow. Each test case consists of three lines. First line of each testcase contains an integer N denoting size of the array. Second line contains N space separated integer denoting elements of the array. Third line of the test case contains an integer K.

Output:
Corresponding to each test case, print the kth smallest element in a new line.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= arr[i] <= 105
1 <= K <= N

Example:
Input:
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
Output:
7
15

Explanation:
Testcase 1: 3rd smallest element in the given array is 7.
Testcase 2: 4th smallest elemets in the given array is 15.
*/



#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n;
    	cin>>n;
    	ll a[n];
    	ll ind;
    	for(ll i=0;i<n;i++)
    	    cin>>a[i];
    	cin>>ind;
    	if(ind>n)
    	{
    	    cout<<"-1"<<endl;
    	    continue;
    	}
    
        sort(a,a+n);
        cout<<a[ind-1]<<endl;
    
	}
	return 0;
}
/*
//merge sort
#include<bits/stdc++.h>
using namespace std;

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
        if(L[i]<R[j])
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
        int m=l+(r-l)/2;
        sort(a,0,m);
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
	    	int a[n];
	    	int ind;
	    	for(int i=0;i<n;i++)
	    	    cin>>a[i];
	    	cin>>ind;
	    	if(ind>n)
	    	{
	    	    cout<<"-1"<<endl;
	    	    continue;
	    	}
		sort(a,0,n-1);
		
		cout<<a[ind-1]<<endl;
	
	
	}
	return 0;
}
*/


//quicksort
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll partition(ll a[],ll l,ll r)
{
    ll pivot=a[l];
    ll i=l,j=r;
    while(i<j)
    {
        while(a[i]<=pivot)
        i++;
        
        while(a[j]>pivot)
        j--;
        
        if(i<j)
        {
            ll temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    ll temp=a[j];
    a[j]=a[l];
    a[l]=temp;
    
    return j;
}
ll sort(ll a[],ll l,ll r,ll k)
{
    if(l<r)
    {
       
        ll j=partition(a,l,r);
        if(j==k)
            return a[j];
        else if(j>k)
           return sort(a,l,j-1,k);
        else 
           return sort(a,j+1,r,k);
    }
    
}
int main()
 {
	//code
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n;
    	cin>>n;
    	ll a[n];
    	ll ind;
    	for(ll i=0;i<n;i++)
    	    cin>>a[i];
    	cin>>ind;
    	if(ind>n)
    	{
    	    cout<<"-1"<<endl;
    	    continue;
    	}
    
        ll x=sort(a,0,n-1,ind-1);
        cout<<a[ind-1]<<endl;
        for(int i=0;i<n;i++)
    	{
    	    cout<<a[i]<<" ";
    	}
	}
	return 0;
}

*/
