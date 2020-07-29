//Phoenix_RK
/*

*******************************************************************************
https://practice.geeksforgeeks.org/problems/finding-the-numbers/0
Find the two non-repeating elements in an array of repeating elements
*******************************************************************************

You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.

Constraints :
1<=T<=100
1<=N<=10^6
1<=A[i]<=5*10^8

Example:
Input :
2
2
1 2 3 2 1 4
1
2 1 3 2

Output :
3 4
1 3

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
    	int a[2*n+2];
    	int XOR;
    	for(int i=0;i<2*n+2;i++)
            cin>>a[i];   
        
        XOR=a[0];
//step1
//XOR of all the numbers in the given array gives the XOR of two unique numbers, because XOR of duplicates will be zero
    	for(int i=1;i<2*n+2;i++)   
    	    XOR=XOR^a[i];
//step2: since the setbits in XOR means that the two numbers have different values in those bits, we can grp the two numbers into different grps based on the set bits.(Any set bit can be used). Since finding the rightmost set bit is easy, it is used here.


    	int set_bit;
    	set_bit = XOR & ~(XOR-1);  // finding the rightmost set bit 
    	int x=0 , y=0;
    	
    	for(int i=0 ;i<2*n+2;i++)
    	{
    	    if(a[i] & set_bit ) //if a number is set at the setbit, then the another number will not be set at the setbit. In this way we are making them to fall into different grps. We need not worry about other numbers as doing XOR of all those duplicates will result in 0.
    	        x=x^a[i];
    	        
    	    else
    	        y = y^a[i];
    	}
    	if(x<y)
    	cout<<x<<" "<<y<<endl;
	   
	    else
	    cout<<y<<" "<<x<<endl;
	}
	return 0;
}
