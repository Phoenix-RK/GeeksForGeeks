//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/majority-element/0

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
int T,n;
	cin>>T;
	while(T--)
	{
	    int s,flag=0,x;
	    cin>>s;
	    vector<int> nums;
	    for(int i=0;i<s;i++)
	    {
	        cin>>x;
	        nums.push_back(x);
	        
	    }
        map<int,int> m;
        
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            m[*it]++;
            if(m[*it]>s/2)
             {
                 flag=1;
                 cout<<*it<<endl;
                 
             }
        }
        if(!flag)
            cout<<"-1"<<endl;;
	
	}
	return 0;
}

/*****************************************************************************/
//Moore's voting algo



//https://www.youtube.com/watch?v=nMm5S109MvM
#include<bits/stdc++.h>
using namespace std;
int candidate(long long int a[],long long int n)
{
   long long int maj_ind=0,count=1,j;
    for(j=1;j<n-1;j++)
    {
        if(a[maj_ind]==a[j])
        count++;
        
        else if(count!=0)
        count--;
        
        else if(count==0)
        {
            count=1;
            maj_ind=j;
        }
        
    }
    return a[maj_ind];
}
int main()
 {
	//code
	long long int T,n,i,j,count,ind,x,a[100000];
	cin>>T;
	while(T--)
	{
	   	cin>>n;
    	
    	for(i=0;i<n;i++)
    	{
    	 cin>>a[i];   
    	}
    	x=candidate(a,n);
    	count=0;
    	for(i=0;i<n;i++)
    	{
    	    if(a[i]==x)
    	    count++;
    	    
    	}
    	
    	if(count>n/2)
    	cout<<x<<endl;
    	
    	else
    	cout<<"-1"<<endl;
	}
	return 0;
}

