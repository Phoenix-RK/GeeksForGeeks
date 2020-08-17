//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0


Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Input:
The first line contains T, denoting the number of testcases. Then follows description of testcases. Each case begins with a single positive integer N denoting the size of array. The second line contains the N space separated positive integers denoting the elements of array A.

Output:
For each testcase, print "Yes" or  "No" whether it is Pythagorean Triplet or not (without quotes).

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= A[i] <= 1000

Example:
Input:
1
5
3 2 4 6 5

Output:
Yes

Explanation:
Testcase 1: a=3, b=4, and c=5 forms a pythagorean triplet, so we print "Yes"



*/



/*

#include<bits/stdc++.h>
using namespace std;
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
	    map<int,int> m;
	    
	    for(int i=0;i<n;i++)
	   {
	       cin>>a[i];
	       m[a[i]*a[i]]++;
	   }
	   int flag=0;
	   for(int i=0;i<n;i++)
	   {
	       for(int j=i+1;j<n;j++)
	       {
	           for(int k=j+1;k<n;k++)
	           {
    	           if(m[a[i]*a[i] + a[j]*a[j]]>0 || m[a[i]*a[i] + a[k]*a[k]]>0 || m[a[k]*a[k] + a[j]*a[j]]>0)
    	           {
    	               
    	               flag=1;
    	               cout<<"Yes"<<endl;
    	               break;
    	           }
    	          
	           }
	            if(flag==1)
	                  break;
	       }
	       if(flag==1)
	         break;
	   }
	   
	   if(flag==0)
	    cout<<"No"<<endl;
	}
	return 0;
}
*/


//Phoenix_RK
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
        sort(a,l,m);
        sort(a,m+1,r);
        
        merge(a,l,m,r);
    }
}

bool check(int a[],int n)
{
// sort the elements in the array
           sort(a,0,n-1);
//using meet in the middle algo try to find if there exists an a[i],a[j],a[k] which are pythagorean triplets.
	   for(int i=n-1;i>=0;i--)
	   {
	       int j=0;
	       int k=i-1;
	       //meet in the middlde algo
	       while(j<k)
	       {
	           if(a[j]+a[k]==a[i])
	               return true;
	           else if(a[j]+a[k]<a[i])
	               j++;
	           else if(a[j]+a[k]>a[i])
	               k--;
	       }
	   }
	   return false;
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
	    //store the square of the elements in the array
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        a[i]=a[i]*a[i];
	    }
	   
	   
	   if(check(a,n))
	    cout<<"Yes"<<endl;
	    else
	    cout<<"No"<<endl;
	}
	return 0;
}
