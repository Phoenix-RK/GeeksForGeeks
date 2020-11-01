//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0#

Given an array, cyclically rotate an array by one.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the array. Then following line contains 'n' integers forming the array. 

Output:
Output the cyclically rotated array by one.

Constraints:
1<=T<=1000
1<=N<=1000
0<=a[i]<=1000

Example:
Input:
2
5
1 2 3 4 5
8
9 8 7 6 4 2 1 3

Output:
5 1 2 3 4
3 9 8 7 6 4 2 1


*****************************************************

Reversal algorithm: O(n)






*/

#include<bits/stdc++.h>
using namespace std;

void reverse(int a[],int l,int r)
{
    int temp;
    while(l<r)
    {
        int temp=a[l];
        a[l]=a[r];
        a[r]=temp;
        
        l++;
        r--;
    }
}


int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        reverse(a,0,n-2);
        reverse(a,0,n-1);
        
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
            
        cout<<endl;
    }
    
    return 0;
}
