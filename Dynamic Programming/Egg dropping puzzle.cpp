//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0

Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3

**************************************************************************
Eg: 3 eggs 5 floors


Every cell represents the minimum no of attempts to determine the critical floor given the no of eggs and no of floors.

Base condition:

1) If there are no eggs or no floors, then in either of the case, there is no need to  attempt. therefore the cells of 0th row and 0th column will hold the value 0.
  0 1 2 3 4 5
--------------
0|0 0 0 0 0 0 
1|0 
2|0  
3|0 

2)If there is only one floor, then only one attempt is required,no matter of how many eggs we possess. therefore, the cells of 

  0 1 2 3 4 5
--------------
0|0 0 0 0 0 0 
1|0 1 2 3 4 5
2|0 1
3|0 1

3) If the no of eggs is greater than the no of floors, then the no of attempts is equal to the no of attempts required by fewer eggs than this for the same no of floors

4) For other situations, 
for any floor, we attempt once ->
the result may be either of the following
 i) the egg may break - in that case , we need to check the attempts required for the no of floors below the floor we are in with one fewer egg(since we broke one egg :( ) //a[i-1][k-1]
 ii)the egg may not break - in that case, we need to check the attempts required by the no of floors above the floor we are in with same no of eggs. //a[i][j-k]

add the maximum of these two with the one attempt we carried out in this floor.
 temp= 1 + max(a[i-1][k-1],a[i][j-k]);

store the minimum of all such possibilities as the minimum no of attempts to locate the critical floor.

*/
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	   int egg, floors;
	   cin>>egg>>floors;
	   
	   int a[egg+1][floors+1];
	   
	   a[0][0]=0;
	   for(int i=1;i<=egg;i++)
	   {
	    a[i][0]=0;
	    a[i][1]=1;
	   }
	   for(int i=1;i<=floors;i++)
	   {
	    a[0][i]=0;
	    a[1][i]=i;
	   }
	   int temp,temp_min;
	   for(int i=2;i<=egg;i++)
	   {
	       for(int j=2;j<=floors;j++)
	       {
	           
	           if(i>j)
	           {
	               a[i][j]=a[i-1][j];
	           }
	           else
	           {
    	           temp_min = INT_MAX;
    	           
    	           for(int k=1;k<=j;k++)
    	           {
    	               temp= 1 + max(a[i-1][k-1],a[i][j-k]);
    	               temp_min=min(temp,temp_min);
    	           }
    	           
    	           a[i][j]= temp_min;
	           }
	       }
	   }
	  /* 
	   for(int i=0;i<=egg;i++)
	   {
	       for(int j=0;j<=floors;j++)
	       {
	           cout<<a[i][j]<<" ";
	       }
	       cout<<endl;
	   }*/
	    cout<<a[egg][floors]<<endl;
	}
	return 0;
}
