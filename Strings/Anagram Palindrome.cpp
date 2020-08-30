//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/anagram-palindrome/0

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

** For More Input/Output Examples Use 'Expected Output' option ** 
*/


//anagram of a string could be palindrome if all the no of characters are even and atmost one char is with odd occurance


#include<bits/stdc++.h>
using namespace std;
bool isFake(string a)
{
    map<char,int> m;
    for(int i=0;i<a.size();i++)
    {
        m[a[i]]++;
    }
    map<char,int>::iterator it;
    int count=0;
    for(it=m.begin();it!=m.end();it++)
    {
        if(((*it).second)%2==1)
        {
            count++;
            if(count>1)
                return false;
        }
            
    }
    return true;
    
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
