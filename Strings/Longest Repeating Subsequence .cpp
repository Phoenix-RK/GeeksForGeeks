//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0#


Given a string str, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of string str.

The second line of each test case contains the string str consisting only of lower case english alphabets.

Output:

Print the length of the longest repeating subsequence for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=1000


Example:

Input:

2

3

abc

5

axxxy

Output:

0

2

*/



#include<bits/stdc++.h>
using namespace std;

int longestRepeating(string s)
{
    int rep[s.length()+1][s.length()+1];
    for(int i=0;i<=s.length();i++)
    {
        rep[i][0]=0;
        rep[0][i]=0;
    }
    
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=s.length();j++)
        {
            if(i!=j && s[i-1]==s[j-1])
            {
                rep[i][j]=rep[i-1][j-1]+1;
            }
            else
                rep[i][j]=max(rep[i-1][j],rep[i][j-1]);
        }
    }
    return rep[s.length()][s.length()];
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m;
        cin>>m;
        string s;
        cin>>s;
        cout<<longestRepeating(s)<<endl;
    }
    return 0;
}


