//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/reverse-the-string/0#


Given a string S as input. You have to reverse the given string.

Input: First line of input contains a single integer T which denotes the number of test cases. T test cases follows, first line of each test case contains a string S.

Output: Corresponding to each test case, print the string S in reverse order.

Constraints:
1 <= T <= 100
3 <= length(S) <= 1000

Example:
Input:
3
Geeks
GeeksforGeeks
GeeksQuiz

Output:
skeeG
skeeGrofskeeG
ziuQskeeG


*****************************************************************
Time complexity - o(n)
*/


#include<bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    int l = s.length();
    
    for(int i=0;i<l/2;i++)
    {
        char c=s[i];
        s[i]=s[l-i-1];
        s[l-i-1]=c;
    }
    return s;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        cout<<reverse(s)<<endl;
    }
    return 0;
}
