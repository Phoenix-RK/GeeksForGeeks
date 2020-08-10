//Phoenix_RK
/*


https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index ).

NOTE: Required Time Complexity O(n2).

Input:
The first line of input consists number of the testcases. The following T lines consist of a string each.

Output:
In each separate line print the longest palindrome of the string given in the respective test case.

Constraints:
1 ≤ T ≤ 100
1 ≤ Str Length ≤ 104

Example:
Input:
1
aaaabbaa

Output:
aabbaa

Explanation:
Testcase 1: The longest palindrome string present in the given string is "aabbaa".

****************************************************************************
Idea:
Iterate through every char of the string
	1)check if this char is the middle element of the palindrome
	2)Expand on both sides and as expanding check if the elements of the boundary are same 
	3) return the length of the palindrome obtained by expanding.
	4)store the start and end of the palindrome which is the longest among all those obtained through iteration.

return the substring in the index of start and end.

**************
racecar
ababd


*/

#include<bits/stdc++.h>
using namespace std;

int length(string s,int left,int right)
{
    if(s.length()==0 || left>right)
        return 0;
        
    while(left>=0 && right<s.length() && s[left]==s[right])
    {
        left--;
        right++;
    }
    
    return right-left-1; 
/*
right - left -1 because when the while loop terminates left is decremented and right is incremented more than necessary ..so in calculation we need to have as (right-1)-(left+1)-1=right-1-left-1+1 = right -left -1;

e.g. racecar (length = 7. Simple math to calculate this would be  R - L  + 1  ( where L= 0 , R=6 )), considering start index is '0'.
Now, in this example ( 'racecar' ) when loop goes into final iteration, that time we have just hit L =0, R =6 (ie. length -1)
but before exiting the loop, we are also decrementing L by L - -  , and incrementing R by R ++ for the final time, which will make L and R as  ( L = -1, R = 7 )
Now, after exiting the loop,  if you apply the same formula for length calculation as 'R - L +1', it would return you 7 -( - 1 )+1 = 9 which is wrong, but point to note is it gives you length increased by 2 units than the correct length which is 7.
So the correct calculation of length would be when you adjust your R and L . to do that you would need to decrease R by 1 unit as it was increased by 1 unit before exiting the loop , and increase L by 1 unit as it was decreased by 1 unit just before exiting the loop.
lets calculate the length with adjusted R and L

(right-1)-(left+1)-1
= right-1-left-1+1 
= right -left -1;
*/
}
string long_palindrome(string s)
{
    if(s.length()<1)
        return "";
    int max_len=0;
    int start=0,end=0;
    
    for(int i=0;i<s.length();i++)
    {
        int len1=length(s,i,i);
        int len2=length(s,i,i+1);
        max_len = max(len1,len2);
        if(max_len > end-start+1)// if many no of palindromes occur of same length, end-start-1 helps to store the first of those longest palindromes
        {
            start = i - ((max_len-1)/2); //i is the index of the middle element..from that setting start 
            end = i + (max_len/2); // similarly setting end
        }
    }
    
    return s.substr(start,end-start+1);
    
    
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	  string s;
	  cin>>s;
	  cout<<long_palindrome(s)<<endl;
	
	}
	return 0;
}
