//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/anagram-1587115620/1#

Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

Note: |s| represents the length of string s.



*/




/*  Function to check if two strings are anagram
*   a, b: input string
*/
bool isAnagram(string a, string b){
    
    // Your code here
    if(a.length()!=b.length())
        return false;
    int isPresent[26]={0};
    
    for(int i=0;a[i]!='\0';i++)
        isPresent[a[i]-'a']++;
    
    for(int i=0;b[i]!='\0';i++)
    {
        isPresent[b[i]-'a']--;
        
        if(isPresent[b[i]-'a']<0)
            return false;
            
    }
    return true;
}

