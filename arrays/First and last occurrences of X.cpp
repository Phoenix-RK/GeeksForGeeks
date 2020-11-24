//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0#


Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Note: If the number x is not found in the array just print '-1'.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case contains two integers n and x. The second line contains n spaced integers.

Output:
Print index of the first and last occurrences of the number x with a space in between.

Constraints: 
1<=T<=100
1<=n,a[i]<=1000

Example:
Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Output:
2 5
6 6



*/


#include<bits/stdc++.h>
using namespace std;

void search(vector<int> a,int& low,int& high,int target)
{
    if((lower_bound(a.begin(),a.end(),target)-a.begin())!=a.size())
        low=lower_bound(a.begin(),a.end(),target)-a.begin();
    if((upper_bound(a.begin(),a.end(),target)-a.begin())!=a.size())
        high=(upper_bound(a.begin(),a.end(),target)-a.begin())-1;
}
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n,target;
        cin>>n>>target;
        vector<int> a;
        int x;
        
        for(int i=0;i<n;i++)
        {
                cin>>x;
                a.push_back(x); 
        }
        int low=-1,high=-1;
            
        search(a,low,high,target);
        if(low==-1 || high==-1 )
            cout<<"-1"<<endl;
        else
            cout<<low<<" "<<high<<endl;
    }
    
    
    
    return 0;

}


//Binary search



//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;

void searchl(int a[],int& low,int target,int n)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+(right-left)/2);
        
        if(a[mid]==target)
        {
            low=(mid<low)?mid:low;
           
            
            right=mid-1;
        }
        else if(a[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    
}

void searchr(int a[],int& high,int target,int n)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        int mid=(left+(right-left)/2);
        
        if(a[mid]==target)
        {
            high=(mid>high)?mid:high;
           
            
            left=mid+1;
        }
        else if(a[mid]<target)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    
}
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n,target;
        cin>>n>>target;
        int a[n];
        
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
        }
        int low=n,high=-1;
            
        searchl(a,low,target,n);
        searchr(a,high,target,n);
        if(low==-1 || high==-1 )
            cout<<"-1"<<endl;
        else
            cout<<low<<" "<<high<<endl;
    }
    
    
    
    return 0;
}
