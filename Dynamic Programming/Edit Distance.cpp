/*

Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    int l1,l2;
	    string word1,word2;
	    cin>>l1>>l2;
	       cin>>word1>>word2;
       int  dp[word1.length()+1][word2.length()+1];
        for(int i=0;i<=word1.length();i++)
        {
            for(int j=0;j<=word2.length();j++)
            {
                if(i==0&& j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=dp[i][j-1]+1;
                
                else if(j==0)
                    dp[i][j]=dp[i-1][j]+1;
                
                else if(word1[i-1]==word2[j-1])
                
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;                    
                
            }
        }
        cout<<dp[word1.length()][word2.length()]<<endl;
        
	    
	
	}
	return 0;
}
