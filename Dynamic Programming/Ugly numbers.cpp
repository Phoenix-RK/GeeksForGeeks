//Phoenix_RK
/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.


*********************************

Reference:https://www.youtube.com/watch?v=78Yx7oLA43s

*********************************


*/
#include<bits/stdc++.h>
using namespace std;
long long int min(long long int a,long long int b)
{
   return a<b?a:b;
}

int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	  long long  int i2=0,i3=0,i5=0,n2,n3,n5,count=0,ugly[n+1];
	   ugly[0]=1;
	    while(count!=n-1)
	    {
	        ugly[count+1]=min(ugly[i2]*2,min(ugly[i3]*3,ugly[i5]*5));
	        
	        if(ugly[count+1]==2*ugly[i2])
	            i2++;
	         if(ugly[count+1]==3*ugly[i3])
	            i3++;
	         if(ugly[count+1]==5*ugly[i5])
	            i5++;
	              
	       count++; 
	        
	    }
	    cout<<ugly[n-1]<<endl;
	
	}
	return 0;
}

