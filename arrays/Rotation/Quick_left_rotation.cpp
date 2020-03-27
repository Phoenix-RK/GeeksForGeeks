//Phoenix_RK
/*
Given an array of size n and multiple values around which we need to left rotate the array.

Input:
1
5 14
1 3 5 7 9
Output:
9 1 3 5 7

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	
	int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        k=k%n;
        int  m=(k+1)%n;
        cout<<a[k]<<" ";
        while(m!=k)
        {
            cout<<a[m]<<" ";
            m=(m+1)%n;
        }
        cout<<endl;

    }
	return 0;
}
