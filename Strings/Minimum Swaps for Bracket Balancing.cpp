//Phoenix_RK

/*



https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing/0#

You are given a string of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer N denoting the length of the string.

The second line of each test case contains the string consisting of '[' and ']'.

Output:

Print the minimum number of swaps to make the string balanced for each test case in a new line.


Constraints:

1<= T <=100

1<= N <=100000

 

Example:

Input  : []][][
Output : 2
First swap: Position 3 and 4
[][]][
Second swap: Position 5 and 6
[][][]

Input  : [[][]]
Output : 0
String is already balanced.




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
        int n;
        cin>>n;
        cin>>s;
        if(s.size()%2)
        {
            cout<<"-1"<<endl;
            continue;
        }
        stack<char> st;
        int count=0;
        // [ ] [ ] ] [ ] [
        // 0 1 2 3 4 5 6 7
        //           i  
        
        //stack = 
        //count = (4-2) + (5-4)+(7-6)
        for(int i=0;i<s.size();i++)
        {
            	if(s[i]=='[')
	            {
    			    st.push(s[i]);
    		    }
        		else if(s[i]==']' && st.empty()==false && st.top()=='[')
        		{
        			st.pop();
        		}
        		else if(s[i]==']')
        		{
        			int j=i+1;
        			while(s[j]!='[')
        			{
        				j++;
        			}
        			if(s[j]=='[')
        			{
        				swap(s[i],s[j]);
        				count = count + (j-i);
        				st.push(s[i]);
        			}
        		}
        }
        cout<<count<<endl;
    }
    
    return 0;
}
