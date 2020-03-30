//Phoenix_RK
//Return two prime numbers
/*
Given an even number (greater than 2), return two prime numbers whose sum will be equal to given number. There are several combinations possible. Print only first such pair. 

Input:
5
74
1024
66 
8
9990

Output:
3 71
3 1021
5 61
3 5
17 9973

*/
#include<bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        return false;
    }
    return true;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    for(int i=2;i<n;i++)
	    {
	        if(isprime(i) && isprime(n-i))
	         {
	             cout<<i<<" "<<n-i<<endl;
	             break;
	         }
	    }
	
	}
	return 0;
}
