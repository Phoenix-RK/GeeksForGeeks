//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/combine-the-strings/0

Given N strings consisting of ‘R’ and ‘B’. Two strings can be only combined if last character of first string and first character of second string are same. Print the maximum length possible by combining strings.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings and the second line contains N space separated strings of equal length.

Output:
For each test case, in a new line print the maximum length possible. If no strings can combine then print "0".

Constraints:
1<=T<=100
2<=N<=1000
1<=|String length|<=1000

Example:
Input:
2
3
RBR BBR RRR
2
RRR BBB

Output:
9
0
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
	
	    string s[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	      int rr= 0, rb = 0, br = 0,bb=0;
          for(int i=0;i<n;i++)
            {
                int len=s[i].size();
                if ( s[i][0] == 'R' && s[i][len- 1] == 'R' )
                {
                    rr++;
                }
                else if ( s[i][0] == 'R' && s[i][len- 1] == 'B' )
                {
                    rb++;
                }
                else if ( s[i][0] == 'B' && s[i][len- 1] == 'B' )
                {
                    bb++;
                }
                else if ( s[i][0] == 'B' && s[i][len- 1] == 'R' )
                {
                    br++;
                }
            }
            int ans;
            int min_val=min(rb,br);
            if(rb==0&&br==0)
                ans=max(rr,bb);
            else if(rb==br)
                ans=rr+bb+(2*min_val);
            else 
                ans=rr+bb+(2*min_val)+1;
            //if all strings are of same length..count the no of strings that could combined and multiply it with the size of the string
            ans=ans*s[0].length();
            if(ans==s[0].length())
                cout<<"0"<<endl;
            else
                cout<<ans<<endl;
	    
	}
	return 0;
}
