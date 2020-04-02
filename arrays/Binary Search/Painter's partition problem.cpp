//Phoenix_RK
/*

Dilpreet wants to paint his dog- Buzo's home that has n boards with different lengths[A1, A2,..., An]. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.The problem is to find the minimum time to get this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

Input:
2
2 4
10 10 10 10
2 4
10 20 30 40
Output:
20
60

***********************************************

https://www.youtube.com/watch?v=9BnC7orwkNA


https://www.youtube.com/watch?v=Ss9ta1zmiZo

***********************************************

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

long long int paint(long long int a[],long long int  n,long long int k)
{
    
    long long int sum=0,max_ele=0;
    for( long long int i=0;i<n;i++)
    {
        sum+=a[i];
        max_ele=max(max_ele,a[i]); 
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
	     long long int  k;
	    cin>>k>>n;
	    long long int  a[n];
	    for(long long int i=0;i<n;i++)
	        cin>>a[i];
	    cin;
	    
	    cout<<paint(a,n,k)<<endl;
	
	}
	return 0;
}
