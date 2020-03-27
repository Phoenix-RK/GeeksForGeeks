//Phonix_RK
/*

********************
ROTATE_ARR_Juggling
Time Complexity:O(n)
          space:O(1)
********************

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
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
  
    else
        return gcd(b, a % b); 
} 
    
void rotate(int *a,int i,int d,int n)
{
 int j=i,t=a[i];
   
    while(1)
    {
        int m=j+d;
        if(m>=n)
           m=m-n;
           
        if(m==i)
           break;
           
       a[j]=a[m];
       
       j=m;
        
    }
    
    a[j]=t;
     
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
      
        int g=gcd(d,n);
        
      
        for(int i=0;i<g;i++)
            rotate(a,i,d,n);
            
          
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
         
        cout<<endl;
    }
	
	return 0;
}

