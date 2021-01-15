//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1#

Given an infix expression in the form of string str. Convert this infix expression to postfix expression.

Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
â€‹Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. 
Example 1:

Input: str = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be abcd^e-fgh*+^*+i-
Example 2:

Input: str = "A*(B+C)/D"
Output: ABC+*D/
Explanation:
After converting the infix expression 
into postfix expression, the resultant 
expression will be ABC+*D/
 
Your Task:
This is a function problem. You only need to complete the function infixToPostfix() that takes a string(Infix Expression) as a parameter and returns a string(postfix expression). The printing is done automatically by the driver code.

Expected Time Complexity: O(|str|).
Expected Auxiliary Space: O(|str|).
*/




// The main function to convert infix expression
//to postfix expression
string infixToPostfix(string s)
{
    // Your code here
    
    
    string postfix="";
    
    stack<char> st;
    map<char,int> m;
    m['+']=1;
    m['-']=1;
    m['*']=2;
    m['/']=2;
    m['^']=3;
    
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            postfix=postfix+s[i];
            continue;
        }
        else if(st.empty() || s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                postfix=postfix+st.top();
                st.pop();
            }
            st.pop();
        }
        else if(m[s[i]] > m[st.top()])
            st.push(s[i]);
        else if(m[s[i]] <= m[st.top()])
        {
            while(!st.empty() && (m[s[i]]<=m[st.top()]))
            {
                postfix=postfix+st.top();
                st.pop();
            }
           st.push(s[i]);
        }
    }
    
    while(!st.empty())
    {
        postfix=postfix+st.top();
        st.pop();
    }
    
    return postfix;
}
