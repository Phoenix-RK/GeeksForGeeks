//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 1:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
Your Task:
Complete the function lcs() which takes the length of two strings respectively and two strings as input parameters and returns the length of the longest subsequence present in both of them.

Expected Time Complexity : O(|str1|*|str2|)
Expected Auxiliary Space: O(|str1|*|str2|)

Constraints:
1<=size(str1),size(str2)<=100


*/



// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    // your code here
    
    vector<vector<int>> a(2,vector<int>(x+1,0));
    a[0][0]=0;
    bool ind=false;
    for(int i=0;i<=y;i++)
    {
        ind=!ind;
        
        for(int j=0;j<=x;j++)
        {
            if(i==0 || j==0)
                a[ind][j]=0;
                
            else if(s1[j-1]==s2[i-1])
                a[ind][j]=a[1-ind][j-1]+1;
            else
                a[ind][j]=max(a[1-ind][j],a[ind][j-1]);
        }
    }
    return a[ind][x];
}




