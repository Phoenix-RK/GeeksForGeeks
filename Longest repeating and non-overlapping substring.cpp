//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring/0


Given a string str, find the longest repeating non-overlapping substring in it. In other words find 2 identical substrings of maximum length which do not overlap. If there exists more than one such substring return any of them.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string str.

The second line of each test case contains the string str.It consists of only lower case english alphabets.

Output:

Print the longest non - overlapping substring for each test case in a new line. If no such sub - sequence exists print -1.


*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
	    int dp[n+1][n+1];
	    memset(dp,0,sizeof(dp));
	    string s;
	    cin>>s;
	    int index=0,max_len=0;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=i+1;j<=n;j++)
	        {
	            if(s[i-1]==s[j-1])
	            {
	                dp[i][j]=dp[i-1][j-1]+1;
    	            if(dp[i][j]>max_len)
    	            {
    	                max_len=dp[i][j];
    	                index=j;
    	            }
	            }
	        }
	    }
	    
	    if(max_len==0)
	        cout<<"-1"<<endl;
	   else
	        cout<<s.substr(index-max_len,max_len)<<endl;
	}
	return 0;
}
