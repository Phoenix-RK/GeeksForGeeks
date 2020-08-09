//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.

Input:
The first line contains T denoting the number of testcases. T testcases follow. Each case contains a string S containing characters.

Output:
For each test case, in a new line, output a single line containing the reversed String.

Constraints:
1 <= T <= 100
1 <= |S| <= 2000

Example:
Input:
2
i.like.this.program.very.much
pqr.mno

Output:
much.very.program.this.like.i
mno.pqr
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
	    string x;
	    int size =s.length()-1;
	    for(int i=size;i>=0;i--)
	    {
	        if(s[i]=='.')
	        {
	            for(int j=i+1;j<i+1+size-i;j++)
	               x=x+s[j];
	       
	             
	
	           x=x+".";
	           size=i-1;
	        }
	        
	    }
	    for(int j=0;j<size+1;j++)
	        x=x+s[j];
	        
	    x=x+'\0';
	    
	    cout<<x<<endl;
	
	}
	return 0;
}
