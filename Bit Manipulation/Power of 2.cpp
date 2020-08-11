//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/power-of-2/0

Given a positive integer N. The task is to check if N is a power of 2. That is N is 2x for some x.

Input:
The first line contains T denoting the number of test cases. Each test case contains a single positive integer N.

Output:
Print "YES" if it is a power of 2 else "NO" (Without the double quotes).

Constraints:
1 <= T <= 100
0 <= N <= 1018

Example:
Input :
2
1
98

Output :
YES
NO

Explanation:
Testcase 1:  1 is equal to 2 raised to 0 (20 == 1).



*/
//METHOD 1
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T;
	cin>>T;
	while(T--)
	{
	    long long int n;
    	cin>>n;
    	if(n==0)
    	{
    	    cout<<"NO"<<endl;
    	    continue;
    	}
    	long long int x = n & (-n); //take bitwise and of n and 2s complement of n
  //take and of n and 1s complement of x
    	if(n&(~x))
    	    cout<<"NO"<<endl;
    	else
    	    cout<<"YES"<<endl;
	
	}
	return 0;
}



//METHOD 2
//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T;
	cin>>T;
	while(T--)
	{
	    long long int n;
    	cin>>n;
    	if(n==0)
    	{
    	    cout<<"NO"<<endl;
    	    continue;
    	}
    	 
    	 if(ceil(log2(n))==floor(log2(n)))
    	    cout<<"YES"<<endl;
    	 else
    	    cout<<"NO"<<endl;
	}
	return 0;
}
