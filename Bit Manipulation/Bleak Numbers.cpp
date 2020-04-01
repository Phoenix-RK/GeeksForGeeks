//Phoenix_RK
//BLEAK NUMBERS
/*
Given an integer, check whether it is Bleak or not.

A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Input:
3
4
167
3

Output:
1
0
0


********************************************************
Reference : how to count no of set bits 
https://www.includehelp.com/cpp-programs/check-if-a-number-is-power-of-2-or-not.aspx
********************************************************
*/
#include<bits/stdc++.h>
using namespace std;
int countSetBit(int n)
{
    int count=0;
    while(n)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}
int main()
 {
	//code
    int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int i=1,flag=0;
	    while(i<n)
	    {
    	    if(i+countSetBit(i)==n)
            	 {
            	     flag=1;
            	      break;
        	    }
        	else
                  i++;
	    }
	      if(flag)
    	        cout<<"0"<<endl;
    	    else
    	        cout<<"1"<<endl;
	
	}
	return 0;
}
