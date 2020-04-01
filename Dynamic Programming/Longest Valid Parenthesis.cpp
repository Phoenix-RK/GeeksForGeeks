//Phoenix_RK
/*
Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

Input:
2
((()
)()())

Output:
2
4

***************************************************
Reference: https://ide.geeksforgeeks.org/C4rbddnN6p
***************************************************

*/
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int longestValidPar(string str)
{
    int n=str.length();
    int dp[n];
   
    int s=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=0;
        if(str[i]=='(')
            s++;
            
        else
        {
            if(s!=0)
            {
                s--;
                dp[i]++;
            }
        }
        
    }
    
    s=0;
    for(int i=n-1;i>=0;i--)
    {
       
        if(str[i]==')')
            s++;
            
        else
        {
            if(s!=0)
            {
                s--;
                dp[i]++;
            }
        }
        
    }
    
    int curr=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==0)
            curr=0;
        else 
        {
            curr++;
        }
        ans=max(ans,curr);
    }
    
    return ans;
}
int main()
 {
	//code
    int T,n;
    string s;
	cin>>T;
	while(T--)
	{
	    cin>>s;
	    cout<<longestValidPar(s)<<endl;
	
	}
	return 0;
}
