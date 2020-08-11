#include<bits/stdc++.h>
using namespace std;
int max_ele(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
    return max;
}
int count_triplet(int a[],int n)
{
       int max=max_ele(a,n);
    map<int,int> m;
 
    for(int i=0;i<=max;i++)
    {
        m[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
  
    int answer=0;
/*
    case 1: 0,0,0  => f(0)C3
    
       f(0)!
    -------------   
    (f(0)-3)! * 3!
*/    

    if(m[0]>2)
        answer +=(m[0])*(m[0]-1)*(m[0]-2)/6;

/*  case 2: 0,x,x => f(x)C2
	  
    f(0) *  f(x)!      f(0) * f(x) * (f(x)-1) 
	  ---------  = ------------------
	(f(x)-2)! 2!          2
*/
     for(int i=1;i<=max;i++)
     {
            answer+= m[0]*(m[i]*(m[i]-1)) /2;
     }
     
/* case 3: x,x,2x => f(x)C2 * f(2x)

   f(x)!       f(2x)
----------- *
(f(x)-2)!2!
*/
     for(int i=1;(2*i)<=max;i++)
     {
         answer+=(m[i] * (m[i]-1) * m[2*i] )/2;
     }
     
/* case 4: x,y,x+y =>f(x) * f(y) * f(x+y)
*/
    for(int i=1;i<=max;i++)
     {
         for(int j=i+1 ; (i+j)<=max;j++)
         {
            answer+=( m[i] * m[j] * m[i+j]);
         }
     }
 
    return (answer==0)?-1:answer;
    
}
int main()
 {
	//code
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
	    cout<<count_triplet(a,n)<<endl;
	 
     
	}
	return 0;
}
