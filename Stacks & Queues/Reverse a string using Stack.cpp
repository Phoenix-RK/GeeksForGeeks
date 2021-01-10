//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1#


You are given a string S, the task is to reverse the string using stack.

Example 1:
Input: S="GeeksforGeeks"
Output: skeeGrofskeeG
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which takes the string S as an input parameter and returns the reversed string.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ length of the string ≤ 100
*/




//return the address of the string
char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    char res[len];
    
    for(int i=0;S[i]!='\0';i++)
        s.push(S[i]);
    int i=0;  
    while(!s.empty())
    {
        S[i++]=s.top();
        s.pop();
    }
 
    return S;
}
