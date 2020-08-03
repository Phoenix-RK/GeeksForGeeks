//Phoenix_RK

/*

Given a string S that represents column title of an Excel sheet, find the number that represents that column.
In excel A column is number 1, AA is 27 and so on.


Input:
The first line contains an integer T, depicting total number of test cases. T testcases follow. Each testcase contains a single line of input containing string S.

Output:
For each testcase, in a new line, print the column number.

Constraints:
1 ≤ T ≤ 100
1 ≤ |S| <=7

Example:
Input
2
A
AA
Output
1
27

*********************************************************************************************
Idea:

This problem is similar to basic numbers 
What is 321 = 3*10*10 + 2*10 + 1

In similar way, We could calculate for AAB.
The difference between the two is that
	1) in the number system, the base is 10. Whereas, in the alphabets the base is 26
	2) in the number system, we take the value of integers as such, but here we need to calculate the value of each character using ASCII

Example:
AAB
Result = Result*26
Result = Result + s[i]-'A' + 1

A =>  0*26 = 0 
      0 + 0 + 1 =1
A =>  1*26 = 26
      26 + 0 + 1 = 27
B =>  27*26 = 702
      702 + 1 + 1 = 704 
  


*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	   
    	string s;
    	cin>>s;
    	int result=0;
    	
    	for(int i=0;i< s.size();i++)
    	{
    	    result = result * 26;
    	    result = result + s[i]-'A' + 1;
    	}
    	
    	cout<< result <<endl;
	
	}
	return 0;
}
