//Phoenix_RK

/*


Given an integer an N. The task is to print the position of first set bit found from right side in the binary representation of the number.

Input:
The first line of the input contains an integer T, denoting the number of test cases. Then T test cases follow. The only line of the each test case contains an integer N.

Output:
For each test case print in a single line an integer denoting the position of the first set bit found form right side of the binary representation of the number. If there is no set bit print "0".

Constraints:
1 <= T <= 200
0 <= N <= 106

Example:
Input:
2
18
12

Output:
2
3

Explanation:
Testcase 1: Binary representation of the 18 is 010010, the first set bit from the right side is at position 2.
 

*****************************************************
010010
1) Take 2's complement of the number. This gives all bits different except for the first 1 from the right.(101110)

2) Do bitwise &. This gives only the required position set to 1.(000010)

3)Take log2 of the result.log2(2^1)=1

4)Add 1 to it (2)

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
	    int n;
    	cin>>n;
    	if(n==0)
    	    cout<<0<<endl;
    	else
    	{
    	    int x= log2(n & -n)+1;
    	    cout<<x<<endl;
    	}
    
	
	}
	return 0;
}
