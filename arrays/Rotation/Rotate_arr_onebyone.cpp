//Phonix_RK
/*
********************
ROTATE_ARR 
Time Complexity:O(n*d)
          space:O(1)

Given an array of N size. The task is to rotate array by d elements where d is less than or equal to N.

Example:
Input
1
5
1 2 3 4 5
2

Output
3 4 5 1 2

*/

#include<bits/stdc++.h>
using namespace std;
void rotate(int *a,int n)
{
    int temp=a[0];
    for(int i=0;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=temp;
}
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>d;
     
       for(int i=0;i<d;i++)
            rotate(a,n);
       for(int i=0;i<n;i++)
         cout<<a[i]<<" ";
         
        cout<<endl;
    }
	
	return 0;
}
