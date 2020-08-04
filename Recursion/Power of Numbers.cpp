//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/power-of-numbers/0

Given a number N, let the reverse of the number be R. The task is to print the output of the Expression pow(N,R), where pow function represents N raised to power R.
Note: As answers can be very large, print the result modulo 1000000007.

Input:
The first line of the input consists of an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of a single line containing an integer N.

Output:
Corresponding to each test case, print in a new line, the output of the expression pow as described above.

Constraints:
1 <= T <= 103
1 <= N <= 1010

Example:
Input:
2
2
12

Output:
4
864354781

*/
#include<bits/stdc++.h>
using namespace std;
#define m  1000000007
long long int reverse(long long int x)
{
    long long int  rev=0;
    
    while(x!=0)
    {
        
        rev = (rev*10) + (x%10);
        x= x/10;
        
    }
    return rev;
}
 long long int func (  long long int x,  long long int n)
{
    
    if(n==0)
        return 1;
    
   long long int power = func(x,n/2);

    if (n%2==0)
     return ((power)*(power))%m;
    else
     return (x*((power*power)%m))%m ;
    
   
}
int main()
 {
	//code
	long long int T;
	cin>>T;
	while(T--)
	{
	    long long int x,n;
	    cin>>x;
	    n= reverse (x);
	    cout<<func(x,n)<<endl;
	
	}
	return 0;
}

