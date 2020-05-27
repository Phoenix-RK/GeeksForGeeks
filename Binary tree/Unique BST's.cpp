//Phoenix_RK

/*

https://www.youtube.com/watch?v=0s20L4-chDA

Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Ouput:
For each testcase, in a new line, print the answer.


for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /        /  \      \
     3        2         1        1    3      2
    /       /            \                    \
   2      1               2                    3


*/


#include<bits/stdc++.h>
using namespace std;

int binomial_coeff(int n,int k)
{
    int res=1;
    
    if(k>n-k)
        k=n-k;
        
    for(int i=0;i<k;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    
    return res;
}
int catalan(int n)
{
    int coeff=binomial_coeff(2*n,n);
    return coeff/(n+1);
}

int main()
 {
	//code
	int T,n;
	cin>>T;
	while(T--)
	{
	    
	    cin>>n;
	    cout<<catalan(n)<<endl;
	
	}
	return 0;
}
