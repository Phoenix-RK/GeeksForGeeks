//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/wildcard-string-matching/0#


Given two strings where first string may contain wild card characters and second string is a normal string. Write a function that returns true if the two strings match. The following are allowed wild card characters in first string.

* --> Matches with 0 or more instances of any character 
      or set of characters.
? --> Matches with any one character.
Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains two strings, a string with wildcard and one without.

Output:
Print "Yes" (without quotes) if the two strings match else print "No" (without quotes).

Constraints:
1<=T<=10^5
1<=length of the two string<=10^5

Example:
Input:
2
ge*ks
geeks
ge?ks*
geeksforgeeks

Output:
Yes
Yes

*/


#include<bits/stdc++.h>
using namespace std;
/*
     0 1 2 3 4 5
       g e * k s
 0   F 
 1 g
 2 e
 3 e
 4 k
 5 s
*/
bool isWildcard(string s1,string s2)
{
    bool val[s1.length()+1][s2.length()+1];
    memset(val,false,sizeof(val));
    
    val[0][0]=true;
    for(int i=1;i<=s2.length();i++)
    {
        if(s2[i-1]=='*')
             val[0][i]=val[0][i-1];       //text null & pattern[i-1] is *  

    }
       
    for(int i=1;i<=s1.length();i++)
    {
        for(int j=1;j<=s2.length();j++)
        {
             if(s2[j-1]=='*' )
                val[i][j] = val[i-1][j] || val[i][j-1];
             
            else if (s2[j-1]==s1[i-1]|| s2[j-1]=='?')
                val[i][j]= val[i-1][j-1];
            
               
            else 
                val[i][j]=false;
        }
    }
  /*  for(int i=0;i<=s1.length();i++)
    {
        for(int j=0;j<=s2.length();j++)
            cout<<val[i][j]<<" ";
        cout<<endl;
    }*/
    return val[s1.length()][s2.length()];
}
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        string s1,s2;
        cin>>s1>>s2;
        
        if(isWildcard(s2,s1))
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    
    
}


