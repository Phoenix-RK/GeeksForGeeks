//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0


Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Note: If you find multiple answers then print the Smallest number found. Also, expected solution is O(n) time and constant extra space.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. The first line of each test case contains a single integer N denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
Print B, the repeating number followed by A which is missing in a single line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ A[i] ≤ N

Example:
Input:
2
2
2 2
3 
1 3 3

Output:
2 1
3 2

Explanation:
Testcase 1: Repeating number is 2 and smallest positive missing number is 1.
Testcase 2: Repeating number is 3 and smallest positive missing number is 2.

*****************************************************
actual: w x y z       
given : w y y z      


 asum= w+x+y+z
 gsum= w+y+y+z
----------------
asum-gsum= x-y
----------------

asumsq         = w2+x2+y2+z2
gsumsq         = w2+y2+y2+z2
--------------------
asumsq-gsumsq  = x2-y2
-------------------


x+y = asumsq-gsumsq
      ______________
       asum-gsum  

solve x+y and x-y to find x and y

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T;
	cin>>T;
	while(T--)
	{
	    long long int n,gsum=0,asum=0,asumsq=0,gsumsq=0,diff,total;
    	cin>>n;
    	long long int a[n];
    	for(long long int i=0;i<n;i++)
	   {
	       cin>>a[i];
	       gsum+=a[i];
	       gsumsq+=a[i]*a[i];
	   }
	   
	   asum=n*(n+1)/2;
	   asumsq= n*(n+1)*(2*n+1)/6;
	   

	   
	   diff = asum - gsum;
	   total= (asumsq- gsumsq)/diff;
	   
	   cout<<(total-diff)/2<<" "<<(total+diff)/2<<endl;
	   
	
	}
	return 0;
}
