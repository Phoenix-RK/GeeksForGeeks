//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/urlify-a-given-string/0#



Write a method to replace all the spaces in a string S with ‘%20’. You may assume that the string has sufficient space (or allocated memory) at the end to hold the additional characters,

Note: The leading and trailing spaces should be trimmed off and not replaced by %20.

Input:
The first line of input contains an integer T denoting the number of test cases. The T test cases follow. Each test case contains two lines of input. The first line contains a string S. The next line contains an integer K that denotes the length of the S with whitespace included.

Output:
For each testcase, in a new line, print the string with spaces replaced by "%20".

Constraints:
1 <= T <= 1000
1 <= |S|+ K <= 1000

Example:
Input:
2
Mr John Smith
13
Mr Benedict Cumberbatch  
25

Output:
"Mr%20John%20Smith"
"Mr%20Benedict%20Cumberbatch

Explanation:
Here in the second case 25 means that there are 25 characters taken into input. While the length of the string is 23 , it means that there are 2 extra spaces at the end which needs to be removed and is contained in input. So the output should be those 23 characters with 2 extra spaces removed and spaces between word replaced with %20.
*/

//Phoenix_RK
#include<iostream>
#include<string>
using namespace std;

string url(string s,int no)
{
    string res="";
    int j=0;
    
    for(int i=0;s[i]!='\0';i++)
   {
       if(s[i]==' ')
       {
           res=res+"%20";
           j=j+3;
       }
       else
       {
           res=res+s[i];
           j++;
       }
       
   }
   res[j]='\0';
   
   return res;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin.ignore();
        getline(cin,s);
        int no;
        cin>>no;
        cout<<url(s,no)<<endl;
    }
    
    return 0;
}
