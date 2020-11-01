//Phoenix_RK

/*

https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/

An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.
Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.


**************************
Two pointer approach - O(n)
*/


#include <bits/stdc++.h>  
using namespace std; 
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
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
        
        
        int left=0,right=n-1;
        
        while(left<right)
        {
            while(left<right && a[left]<0)
                left++;
            
            while(left<right && a[right]>=0)
                right--;
                
            if(left<right)
            {
                swap(&a[left],&a[right]);
            }
        }
        
        
        
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        
        cout<<endl;
    }
}
