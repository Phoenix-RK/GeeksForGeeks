//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/anagram-palindrome/0#

Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 
For example characters of “geeksogeeks” can be rearranged to form a palindrome “geeksoskeeg”, but characters of “geeksforgeeks” cannot be rearranged to form a palindrome.

Input:
First line consists of integer T  denoting the number of test cases. T testcases follow. For each testcase there are one line of input containing string S.

Output:
For each testcase, in a new line, print "Yes" if is possible to make it a palindrome, else "No".

Constraints:
1 <= T <= 100
1 <= |S| <= 1000

Example:
Input:
2
geeksogeeks
geeksforgeeks
Output:
Yes
No



*/

#include<bits/stdc++.h>
using namespace std;
bool isFake(string a)
{
    int bitvector=0,mask=0;
    for(int i=0;a[i]!='\0';i++)
    {
        int x=a[i]-'a';
        mask= 1<<x;
    
        bitvector=bitvector^mask;
    }
    
    return (bitvector&(bitvector-1))==0;
    
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s1;
	    cin>>s1;
	    if(isFake(s1))
	        cout<<"Yes"<<endl;
	    else
	        cout<<"No"<<endl;
	}
	return 0;
}
