//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/sort-string/0/

Given a string of lowercase characters from ‘a’ – ‘z’. We need to write a program to print the characters of this string in sorted order.

Input:
The first line contains an integer T, denoting number of test cases. Then T test case follows. First line of each test case contains a string S each.

Output:
For each test case, print the string S in sorted order.

Constraints:
1<=T<=100
1<=|S|<=4*10^4
String S will contains lowercase character from 'a'-'z

Example:
Input:
2
bbccdefbbaa
geeksforgeeks
Output :
aabbbbccdef
eeeefggkkorss


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        
        map<char,int> m;
        
        for(int i=0;s[i]!=0;i++)
        {
            m[s[i]]++;
        }
        int x=0;
        map<char,int>:: iterator it;
        for(it=m.begin();it!=m.end();it++)
        {
            int m=it->second;
            while(m--)
                s[x++]=it->first;
        }
   
        cout<<s<<endl;
        
    }
    return 0;
}

