//Phoenix_RK
/*

Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have same width and the width is 1 unit.

Example:
Input: 
2
7
6 2 5 4 5 1 6
4
6 3 4 2
Output:
12
9




****************************************************
Reference : Tushor roy tutorial
https://www.youtube.com/watch?v=ZmnqCZp9bBs
*****************************************************

*/
#include<bits/stdc++.h>
using namespace std;
long long int find_area(long long int a[],long long int n)
{
    stack<long long int> s;
    
    long long int i=0;
     long long int area=0,max_area=0;
    for(i=0;i<n;)
    {
        if(s.empty() || a[s.top()]<=a[i])
          {
              s.push(i);
              i++;
            }
        else
        {
            long long int t=s.top();
            s.pop();
            if(!s.empty())
            {
               area=a[t]*(i-s.top()-1);
            }
            else
              area=a[t]*i;
                 
            if(area>max_area)
                max_area=area;
       }
        
    }

    while(!s.empty())
    {
    long long int t=s.top();
      s.pop();
      if(!s.empty())
      {
          area=a[t]*(i-s.top()-1);
      }
        else
        area=a[t]*i;
        
    if(area>max_area)
        max_area=area;
    }
    
    
    return max_area;
}
int main()
 {
	//code
    long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	   long long int a[n];
	    for(long long int i=0;i<n;i++)
	        cin>>a[i];
	        
	   cout<<find_area(a,n)<<endl;
	   
	
	}
	return 0;
}
