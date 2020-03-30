//Phoenix_RK
//Sum of permutations
/*
*******************************************
reference:https://www.youtube.com/watch?v=PQ5OySVcvSQ
*******************************************
Given N distinct digits in an array A (from 1 to 9), Your task is to complete the function getSum which finds sum of all n digit numbers that can be formed using these digits. 

2
3
1 2 3
2
1 2
Output:
1332
33

Explanation:
For first test case
the numbers formed will be 123 , 132 , 312 , 213, 231 , 321
sum = 123 + 132 + 312 + 213 + 231 + 321 = 1332
*/
#include <bits/stdc++.h>
using namespace std;


long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<getSum(a,n)<<endl;
	}
	return 0;
}// } Driver Code Ends
/*You are required to complete this method */
long long int fact(long long int x)
{
    if(x==0)
        return 1;
    else
       return x*fact(x-1);
}
long long getSum(int A[],int n)
{
    //Your code here
   long long int sum_arr=0,sum=0,sum_place=0;
    for(long long int i=0;i<n;i++)
    {
        sum_arr+=A[i];
      
    }
    for(long long int i=0;i<n;i++)
    {
        sum_place+=pow(10,i);
        
    }
   return (fact(n-1)*sum_arr*sum_place)%(1000000007);
    
}
