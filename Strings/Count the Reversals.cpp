//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/count-the-reversals/0#


Given a string S consisting only of opening and closing curly brackets '{' and '}' find out the minimum number of reversals required to make a balanced expression.

Input
The first line of input contains an integer T, denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a string S consisting only of { and }.

Output
Print out minimum reversals required to make S balanced. If it cannot be balanced, then print -1.

Constraints
1 <= T <= 100
0 <= |S| <= 50

Examples
Input
4
}{{}}{{{
{{}}}}
{{}{{{}{{}}{{
{{{{}}}}

Output
3
1
-1
0

Explanation:
Testcase 1: For the given string }{{}}{{{ since the length is even we just need to count the number of openning brackets('{') suppose denoted by 'm' and closing brackest('}') suppose dentoed by 'n' after removing highlighted ones. After counting compute ceil(m/2) + ceil(n/2).

*/



//Phoenix_RK
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
        if(s.size()%2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        stack<char> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
                if(st.top()=='{' && s[i]=='}')
                     st.pop();
                else 
                    st.push(s[i]);
            }
            else 
                st.push(s[i]);
        }
    
        double close_count=0,open_count=0;
        
        while(!st.empty())
        {
            if(st.top()=='{')
                open_count++;
            else
                close_count++;
                
            st.pop();
        }
        cout<<(ceil(open_count/2)+ ceil(close_count/2))<<endl;
    }
    
    return 0;
}




