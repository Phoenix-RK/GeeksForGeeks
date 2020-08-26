//Phoenix_RK



/*

https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array/0


Given a array of N strings, find the longest common prefix among all strings present in the array.

Input:
The first line of the input contains an integer T which denotes the number of test cases to follow. Each test case contains an integer N. Next line has space separated N strings.

Output:
Print the longest common prefix as a string in the given array. If no such prefix exists print "-1"(without quotes).

Constraints:
1 <= T <= 103
1 <= N <= 103
1 <= |S| <= 103

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

Explanation:
Testcase 1: Longest common prefix in all the given string is gee.
*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
    	cin>>n;
    	if(n==0)
    	    continue;
    	string s;
    	vector<string> words;
    	int len=INT_MAX;
    
    	for(int i=0;i<n;i++)
    	{
    	    cin>>s;
    	    len=min(len,s.size());
    	    //cout<<len<<endl;
    	    words.push_back(s);
    	}
    	if(n==1)
	   {
	       cout<<words[0]<<endl;
	       continue;
	   }
    	string prefix="";
        char c;	
        int i=0,flag=0;
        
      //  cout<<len<<endl;
        while(i!=len)
        {
            c=words[0][i];
            for(int j=1;j<n;j++)
            {
                if(c==words[j][i])
                {
                   continue;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
            else
                prefix=prefix+c;
            i++;
        }
        if(prefix.length()>=1)	
            cout<<prefix<<endl;
	    else
	        cout<<"-1"<<endl;
	}
	return 0;
}
