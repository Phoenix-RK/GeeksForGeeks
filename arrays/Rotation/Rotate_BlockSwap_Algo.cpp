//Phonix_RK
/*

********************
ROTATE_BlockSwap
Time Complexity:O(n)
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

ITERATIONS
1 2 3 4 5
i=2
j=5-2=3
i<j
d-i=2-2=0
d+j-i=2+3-2=3
4 5 3 1 2

i=2
j=3-2=1
j<i
d-i=2-2=0
d=2
3 5 4 1 2

i=1
j=1
i==j
d-i=2-1=1
d=2
3 4 5 1 2
*/

#include<bits/stdc++.h>
using namespace std;
void swap_block(int *a,int x,int y,int n)
{
    int i=0;
    while(i<n)
    {
        int temp=a[x+i];
        a[x+i]=a[y+i];
        a[y+i]=temp;
        i++;
    }
}
void rotate(int *a,int d,int n)
{
    if(d==0||d==n)
        return ;
    
    int i=d,j=n-d;
    
    while(i!=j)
    {
        if(i<j)
        {
            swap_block(a,d-i,d+j-i,i);
            j=j-i;
        }
        else
        {
            swap_block(a,d-i,d,j);
            i=i-j;
        }
    }
    swap_block(a,d-i,d,i); //when i==j
    return;
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
      
        rotate(a,d,n);
            
          
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
         
        cout<<endl;
    }
	
	return 0;
}

