//Phoenix_RK
/*
You are given N number of books. Every ith book has Pi number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations, and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated atleast one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see explanation for better understanding).

*************************************
Reference : https://www.youtube.com/watch?v=Ss9ta1zmiZo


************************************

*/
#include<bits/stdc++.h>

using namespace std;
long long int max(long long int a,long long int b)
{
    return a>b?a:b;
}
bool valid(long long int a[],long long int  n,long long int  k,long long int  mid)
{
    long long int curr=0,count=1;
    for(long long int i=0;i<n;i++)
    {
        if(curr+a[i]>mid)
        {
            curr=a[i];
            count++;
            if(count>k)
                return false;
        }
        else
            curr+=a[i];
    }
    return true;
    
}

long long int page(long long int a[],long long int  n,long long int k)
{
    if(n<k)
    return -1;
    long long int sum=0,max_ele=0;
    for( long long int i=0;i<n;i++)
    {
        sum+=a[i];
        max_ele=max(max_ele,a[i]); //each student will read atleast one book and the book with max no of pages is the starting pt
    }
    
     long long int start=max_ele,end=sum,ans=0;
    
    while(start<=end)
    {
         long long int mid=(start+end)/2;
        
        if(valid(a,n,k,mid))
        {
            ans=mid;
            end=mid-1;
            
        }
        else
        {
            start=mid+1;
            
        }
    }
    return ans;
}
int main()
 {
	//code
     long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    long long int  a[n],k;
	    for(long long int i=0;i<n;i++)
	        cin>>a[i];
	    cin>>k;
	    
	    cout<<page(a,n,k)<<endl;
	
	}
	return 0;
}
