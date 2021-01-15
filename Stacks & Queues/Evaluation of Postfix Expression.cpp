//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1#


Given string S representing a postfix expression, the task is to evaluate the expression and find the final value. Operators will only include the basic arithmetic operators like *, /, + and -.

 

Example 1:

Input: S = "231*+9-"
Output: -4
Explanation:
After solving the given expression, 
we have -4 as result.
 

Example 2:

Input: S = "123+*8-"
Output: -3
Explanation:
After solving the given postfix 
expression, we have -3 as result.

Your Task:
You do not need to read input or print anything. Complete the function evaluatePostfixExpression() that takes the string S denoting the expression as input parameter and returns the evaluated value.


Expected Time Complexity: O(|S|)
Expected Auixilliary Space: O(|S|)
*/


// The main function that returns value of a given postfix expression
int evaluatePostfix(string S)
{
    // Your code here
    
    
    stack<int> s;
    
    for(int i=0;S[i]!='\0';i++)
    {
        if(S[i]>='0' && S[i]<='9')
            s.push(S[i]-'0');
        else 
        {
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
       
           switch(S[i])
           {
                case '*':
                    s.push(a*b);
                    break;
                case '+':
                    s.push(a+b);
                    break;
                case '-':
                    s.push(a-b);
                    break;
                case '/':
                    s.push(a/b);
                    break;
                default:
                    break;
           }
        }
    }
    return s.top();
}

