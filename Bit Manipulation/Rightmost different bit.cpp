//Phoenix_RK
/*
Given two numbers M and N. The task is to find the position of rightmost different bit in binary representation of numbers.

Input:
The input line contains T, denoting the number of testcases. Each testcase follows. First line of each testcase contains two space separated integers M and N.

Output:
For each testcase in new line, print the position of rightmost different bit in binary representation of numbers. If both M and N are same then print -1 in this case.

Constraints:
1 <= T <= 100
1 <= M <= 103
1 <= N <= 103

Example:
Input:
2
11 9
52 4

Output:
2
5

Explanation:
Tescase 1: Binary representaion of the given numbers are: 1011 and 1001, 2nd bit from right is different.

***********************************************************

1)EXOR to find bits that are different
2)To find the first rightmost set bit, perform bitwise and with 2s complement 
3)take log2 to get the position
4)add 1 to get the actual position

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
	    int m,n;
    	cin>>m>>n;
    /*	1 0 1 1
    	1 0 0 1
    -------------
        0 0 1 0
   &    1 1 1 0
    --------------
        0 0 1 0
log2(0010) = 1 +1=2
    */
        
    	int exor=m^n;
    	int ans=log2(exor & -exor)+1;
    	cout<<ans<<endl;
	
	}
	return 0;
}
