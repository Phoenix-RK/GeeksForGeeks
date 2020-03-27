//Phoenix_RK
/*
Given a sorted array A of size N. The array is rotated 'K' times. Find the value of 'K'. The array may contain duplicate elements.


Input
2
5
5 1 2 3 4
5
1 2 3 4 5
Output
1
0
*/

#include<bits/stdc++.h>
using namespace std;
long int find_pivot(long int *a,long int low,long int high)
{
    long int rot=0;
  for(long int i=1;i<high;i++)
  {
      if(a[i]<a[i-1])
      {
          return i;
      }
  }
  return rot;

}

int main()
 {
	//code
	 int t;
    cin>>t;
    while(t--)
    {
        long int n,d;
        cin>>n;
     long  int a[n];
        for(long int i=0;i<n;i++)
            cin>>a[i];
       
        long int pivot=find_pivot(a,0,n);
       
        cout<<pivot;
        
        cout<<endl;
    }
	return 0;
}
