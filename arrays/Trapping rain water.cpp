#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   
	   int left[n],right[n];
	   left[0]=a[0];
	   for(int i=1;i<n;i++)
	       left[i]=max(left[i-1],a[i]);
	   
	   right[n-1]=a[n-1];
	   for(int i=n-2;i>=0;i--)
	       right[i]=max(right[i+1],a[i]);
	       
	   int ans=0;
	   for(int i=0;i<n;i++)
	   {
	       ans+=min(left[i],right[i])-a[i];
	   }
	    cout<<ans<<endl;
	}
	return 0;
}


/*
Type2

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   
	   int lo=0,hi=n-1,ans=0,left_max=0,right_max=0;
	   while(lo<=hi)
	   {
	       if(a[lo]<a[hi])
	       {
	           if(a[lo]>left_max)
	           {
	               left_max=a[lo];
	           }
	            ans+=left_max-a[lo];
	            lo++;
	           
	       }
	       else
	       {
	           if(a[hi]>right_max)
	           {
	               right_max=a[hi];
	           }
	            ans+=right_max-a[hi];
	            hi--;
	           
	       }
	   }
	
	    cout<<ans<<endl;
	}
	return 0;
}


*/
