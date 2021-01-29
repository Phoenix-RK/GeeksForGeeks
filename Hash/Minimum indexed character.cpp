//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/minimum-indexed-character0221/1/

Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Output the character in patt that is present at the minimum index in str. Print "$" (without quotes) if no character of patt is present in str.

User Task:
The task is to complete the function printMinIndexChar() which finds the character in patt that is present at minimum index in str.

Constraints:
1 <= T <= 105
1 <= |str|, |patt| <= 105

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
$

Explanation:
Testcase 1: e is the character which is present in given patt "geeksforgeeks" and is first found in str "set".

*/



// function to find the minimum index character
// str: string given in the input
// patt: given pattern
string printMinIndexChar(string str, string patt)
{
	
	string s="$";
	
	map<char,int> m;
	
	for(int i=0;patt[i]!='\0';i++)
	    m[patt[i]]=1;
	 
	for(int i=0;str[i]!='\0';i++)
	{
	    if(m[str[i]]==1)
	    {
	        s[0]=str[i];
	        break;
	    }

	}
	
	return s;
}


