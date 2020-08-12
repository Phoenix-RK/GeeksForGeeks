//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0


Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2



*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
 {
	//code
	long long int T,n,l1,l2;
	string s1,s2;
	cin>>T;
	while(T--)
	{
	    cin>>l1>>l2;
	    
	    cin>>s1>>s2;
	    
	    int mem[l1+1][l2+1]={0};
	    for(int i=0;i<=l1;i++)
	    {
	        for(int j=0;j<=l2;j++)
	        mem[i][j]=0;
	    }
	    
	    
	    for(int i=1;i<=l1;i++){
	        
	        for(int j=1;j<=l2;j++)
	        {
	            if(s1[i-1]==s2[j-1]){
	                mem[i][j]=mem[i-1][j-1]+1;
	            }
	            else
	                mem[i][j]=max(mem[i-1][j],mem[i][j-1]);
	        }
	    }
	    
	    cout<<mem[l1][l2]<<endl;
	
	}
	return 0;
}
