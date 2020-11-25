//Phoenix_RK
/*

Given an integer n, calculate the square of a number without using *, / and pow(). 

Even
-----
n = 2*x
n^2 = (2*x)^2 = 4 * (x^2)

Odd
---

n = 2*x + 1
n^2 = (2*x + 1)^2 = 4*(x^2) + 4*x + 1


*/
#include<bits/stdc++.h>
using namespace std;

int calc_sq(int n)
{
	if(n==0)
		return 0;
	if(n<0)
		n=-n;

	if(n%2)
		return ( (calc_sq(n/2)<<2) + ((n/2)<<2) + 1 ) ;
	else
		return (calc_sq(n/2)<<2);
}

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		int n;
		cin>>n;
		cout<<calc_sq(n)<<endl;
	}

	return 0;
}
