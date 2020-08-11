//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1 <= T <= 50
1 <= length of a, b < 100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor

Output:
1
0

Explanation:
Testcase 1: amazon can be rotated anti-clockwise by two places, which will make it as azonam.

Testcase 2: geeksgeeksfor can't be formed by any rotation from the given word geeksforgeeks.






*/


#include<bits/stdc++.h>
using namespace std;
int rotate(string m,string n)
{
    int i=0,ind=0,flag=0;
	   for( i=0;i<m.length()-2;i++)
	   {
	       if(m[i]!=n[i+2])
	       {
	           flag=1;
	           break;
	       }
	       else
	        continue;
	   }
	   if(!flag)
	   {
	    for(;i<2;i++)
	    {
	        if(m[i]!=n[ind++])
	        {
	            flag=1;
	            break;
	        }
	    }
	   }
	   
	   
	 return flag?0:1;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	   string n,m;
	   cin>>n>>m;
	   
	   int flag1=rotate(m,n);
	   int flag2=rotate(n,m);
	   
	   if(flag1||flag2)
	    cout<<1<<endl;
	   else
	    cout<<0<<endl;
	   
	}
	return 0;
}
