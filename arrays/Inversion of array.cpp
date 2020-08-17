//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/inversion-of-array/0/

Given an array of positive integers. The task is to find inversion count of array.

Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.

Output:
Print the inversion count of array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C ≤ 1018

Example:
Input:
1
5
2 4 1 3 5

Output:
3

Explanation:
Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
ll merge(ll a[],ll l,ll m,ll r)
{
    
    ll n1=m-l+1;
    ll n2=r-m;
    ll inv_count=0;
    ll L[n1],R[n2];
    
    for(ll i=0;i<n1;i++)
        L[i]=a[l+i];
        
    for(ll i=0;i<n2;i++)
        R[i]=a[m+i+1];
        
    ll i=0,j=0,k=l;
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
            inv_count+=n1-i;
            j++;
        }
        
        k++;
    }
    while(i<n1)
    {
        a[k]=L[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        k++;
        j++;
    }
    return inv_count;
}
ll sort(ll a[],ll l,ll r)
{
    ll inv_count=0;
    if(l<r)
    {
        ll m=l+(r-l)/2;
        
        inv_count+=sort(a,l,m);
      
        inv_count+=sort(a,m+1,r);
              
        inv_count+=merge(a,l,m,r);
      
    }
    
    return inv_count;
}
int main()
 {
	//code
	ll T;
	cin>>T;
	while(T--)
	{
	    ll n;
    	cin>>n;
    	ll a[n];
    	
    	for(ll i=0;i<n;i++)
    	    cin>>a[i];
    	    
    	cout<<sort(a,0,n-1)<<endl;
	
	}
	return 0;
}
