//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/parenthesis-checker/0

Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the program should print 'balanced' for exp = “[()]{}{[()()]()}” and 'not balanced' for exp = “[(])”

Input:
The first line of input contains an integer T denoting the number of test cases.  Each test case consists of a string of expression, in a separate line.

Output:
Print 'balanced' without quotes if the pair of parenthesis is balanced else print 'not balanced' in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ |s| ≤ 105

Example:
Input:
4
{([])}
()
([]
()}
Output:
balanced
balanced
not balanced
not balanced

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
	    stack<char> st;
	    int flag=0;
	    cin>>s;
	    for(int i=0;i<s.size();i++)
	    {
	        
	        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
	        {
	               st.push(s[i]);
	               continue;
	        }
	        else
	        {
    	        if(st.empty()) //there is a closing element but there is no opening element
    	        {
    	            flag=1;
    	            break;
    	        }
	       
	            else if((s[i]==')' && st.top()=='(') || (s[i]=='}' && st.top()=='{' ) || (s[i]==']'  && st.top()=='[') )
	            {
	              
	                st.pop();
	            }
	            else
	            {
	                flag=1;
	                break;
	            }
	        }
	    }
	    if(!st.empty()) //there is an opening element but there is no closing element
	        flag=1;
	        
	 
	    if(flag==0)
	        cout<<"balanced"<<endl;
	   else
	     cout<<"not balanced"<<endl;


	}
	return 0;
}
