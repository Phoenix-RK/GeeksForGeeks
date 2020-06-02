//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0

Given a string S, find length of the longest substring with all distinct characters.  For example, for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.



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
	   string s;
	   int a[26];
	   memset(a,-1,sizeof(a));
	   
       cin>>s;
	   int len=0,i=0,j;
	   for(int j=0;j<s.length();j++)
	   {
	       i= max(i,a[s[j]-'a']+1);
	       len=max(len,j-i+1);
	       a[s[j]-'a']=j;
	   }
	  
	   cout<<len<<endl;         
	  
	}
	return 0;
}
