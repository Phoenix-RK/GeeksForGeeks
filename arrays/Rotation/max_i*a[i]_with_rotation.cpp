//Phoenix_RK
/*
Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i].

example:
Input: arr[] = {1, 20, 2, 10}
Output: 72

Logic

Calculate sum for ith rotation
if ith sum is greater than i-1 th sum make it max value

The difference between ith and i-1 th sum comes in the pattern

Si -Si-1 = sum -n*(a[n-j])
*/
#include<iostream>
using namespace std;
int main() {
	//code
    int t,n;
    cin>>t;
    while(t--){
    
      cin>>n;
       int a[n],sum=0,curr=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
           sum=sum+a[i];
           curr=curr+(i*a[i]);
        }
      int max=curr;
        
        for(int j=1;j<n;j++)
        {
            curr=curr+sum-n*a[n-j];
            if(curr>max)
                max=curr;
        }
    
   cout<<max<<endl;
   
    }
}
