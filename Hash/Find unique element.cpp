//Phoenix_RK
/*


https://practice.geeksforgeeks.org/problems/find-unique-element/0/


Given an array which contains all elements occurring k times, but one occurs only once. Find that unique element.

Input:
The first line consists of an integer T i.e number of test cases. The first line of each test case consists of two integers n and k. The next line consists of n spaced integers. 

Output:
Print the required output.

Constraints: 
1<=T<=100
2<=k 1<=a[i]<=10000

Example:
Input:
2
7 3
6 2 5 2 2 6 6 
5 4
2 2 2 10 2

Output:
5
10


*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int T;
    cin>>T;
    
    while(T--)
    {
        long long int n,k;
        
        cin>>n>>k;
        long long int a[n];
        for(long long int i=0;i<n;i++)
            cin>>a[i];
        
        
        map<long long int,long long int> m;
        
        for(long long int i=0;i<n;i++)
        {
            m[a[i]]++;
        }
        map<long long int,long long int> :: iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second!=k)
            {
                cout<<it->first<<endl;
                break;
            }
        }   
    }
    
    return 0;
}
