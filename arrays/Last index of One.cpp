//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/last-index-of-1/0


Given a string S consisting only '0's and '1's,  print the last index of the '1' present in it.

Input:
First line of the input contains the number of test cases T, T lines follow each containing a stream of characters.

Output:
Corresponding to every test case, output the last index of 1. If 1 is not present, print "-1" (without quotes).

Constraints:
1 <= T <= 110
1 <= |S| <= 106

Example:
Input:
2
00001
0
Output:
4
-1

Explanation:
Testcase 1: Last index of  1 in given string is 4.
Testcase 2: Since, 1 is not present, so output is -1.

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
	    cin>>s;
	    int flag=0;
	    for(int i=s.length()-1;i>=0;i--)
	    {
	        if(s[i]=='1')
	        {
	            flag=1;
	            cout<<i<<endl;
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"-1"<<endl;
	
	}
	return 0;
}
