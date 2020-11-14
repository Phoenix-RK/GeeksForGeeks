//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0#


Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2




*/


#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;

int mult(int r[],int size,int x)
{
    int carry=0;
    
    for(int i=0;i<size;i++)
    {
      int prod=r[i]*x+carry;
       r[i]=prod%10;
       carry=prod/10;
    }
    while(carry)
    {
        r[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
    
}
int factorial(int x)
{
    int i,r[MAX],size=1;
    r[0]=1;
    for(i=2;i<=x;i++)
    {
        size=mult(r,size,i);
    }
    
    for(i=size-1;i>=0;i--)
    {
        cout<<r[i];
    }
 }
int main()
 {
	long long int T,n,x;
	cin>>T;
	while(T--)
	{
	    cin>>x;
	    factorial(x);
	    cout<<endl;
	
	}
	return 0;
}
