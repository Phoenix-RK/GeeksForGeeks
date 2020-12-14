//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#


Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
 

Your Task:  
You don't need to read input or print anything. Complete the function isPlaindrome() which accepts string S and returns a boolean value


Expected Time Complexity: O(Length of S) 
Expected Auxiliary Space: O(1) 


Constraints:
1 <= Length of S <= 105


*/



//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    // Your code goes here
	    int left=0,right=S.length()-1;
	    
	    while(left<right)
	    {
	        if(S[left]!=S[right])
	            return 0;
	       left++;
	       right--;
	    }
	    return 1;
	}

};
