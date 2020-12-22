//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/longest-common-substring/0#


Given two strings X and Y. The task is to find the length of the longest common substring.

Input:
First line of the input contains number of test cases T. Each test case consist of three lines, first of which contains 2 space separated integers N and M denoting the size of string X and Y strings respectively. The next two lines contains the string X and Y.

Output:
For each test case print the length of longest  common substring of the two strings .

Constraints:
1 <= T <= 200
1 <= N, M <= 100

Example:
Input:
2
6 6
ABCDGH
ACDGHR
3 2
ABC
AC

Output:
4
1

Example:
Testcase 1: CDGH is the longest substring present in both of the strings.

*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;

int longest_substring(int x1,int x2,string s1,string s2)
{
    int len[x1+1][x2+1];
    memset(len,0,sizeof(len));
    //len[0][0]=1;
    int length=-1;
    
    for(int i=1;i<=x1;i++)
    {
        for(int j=1;j<=x2;j++)
        {
            if(s1[i-1]==s2[j-1])
                len[i][j]=len[i-1][j-1]+1;
            
            else
                len[i][j]=0;
                
            length=max(length,len[i][j]);
        }
    }
    
   /* 
    for(int i=0;i<=x1;i++)
    {
        for(int j=0;j<=x2;j++)
            cout<<len[i][j]<<" ";
            
        cout<<endl;
    }*/
    
    
    return length;
    
    
}
int main()
{
    int T;
    
    cin>>T;
    
    while(T--)
    {
        int x1,x2;
        cin>>x1>>x2;
        string s1,s2;
        cin>>s1>>s2;
        
        cout<<longest_substring(x1,x2,s1,s2)<<endl;
        
    }
    
    
    return 0;
}

