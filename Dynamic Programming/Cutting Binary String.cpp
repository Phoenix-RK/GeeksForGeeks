//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/cutting-binary-string/0/

Given a string s containing 0's and 1's. You have to return a smallest positive integer C, such that the binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.

Input:
The first line of the input contains T denoting the number of test cases. For each test case, there is a string s.

Output:
For each test case, the output is an integer C. If no such cuts are possible then return -1. 

Constraints:
1<=s.length()<=50
Note: The string s is a binary string.

Example:
Input
3
101101101
1111101
00000
Output:
3
1
-1

Explanation:
1.We can split the given string into three “101”s, where 101 is the binary representation of 5.
2."1111101 " is 125 which is 5^3.
3.0 is not a power of 5.



*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
bool isPower(long val,int base)
{
    while(val>1)
    {
        if(val%base!=0)
            return false;
        val=val/base;
    }

    return true;
    
}

int noOfCuts(string s)
{
    
    int i,j,n=s.length();
    
    int dp[n];
    if(s[n-1]-'0'==0)
        dp[n-1]=-1;
    else
        dp[n-1]=1;
        
    for(i=n-2;i>=0;i--)
    {
        if(s[i]-'0'==0)
        {
            dp[i]=-1;
            continue;
        }
        dp[i]=INT_MAX;
        long val=0;
        for(j=i;j<n;j++)
        {
            val=(val*2)+ (long)(s[j]-'0');
            
            if(isPower(val,5))
            {
                if(j==n-1)
                    dp[i]=1;
                else
                {
                    if(dp[j+1]!=-1)
                        dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
        }
        if(dp[i]==INT_MAX)
            dp[i]=-1;
    }
   
    return dp[0];
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    cout<<noOfCuts(s)<<endl;
	
	}
	return 0;
}
