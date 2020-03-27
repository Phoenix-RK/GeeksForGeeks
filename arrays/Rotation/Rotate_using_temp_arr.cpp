//Phonix_RK
/*

****************************************
ROTATE_TEMP_ARR  
Time complexity : O(n)
          Space : O(d)
****************************************

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
        int temp[d];
        
       for(int i=0;i<d;i++)
         temp[i]=a[i];
   
       int j=0;
       for(int i=d;i<n;i++)
         a[j++]=a[i];
        
       for(int i=0;i<d;i++)
         a[j++]=temp[i];
          
       for(int i=0;i<n;i++)
         cout<<a[i]<<" ";
        cout<<endl;
    }
	
	return 0;
}
