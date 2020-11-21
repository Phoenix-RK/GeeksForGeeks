//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0#


Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Input:
The first line of input contains integer T denoting the number of test cases. For each test case,  the first line of input contains an integer n denoting the size of the array. Next line contains n space separated integers denoting the elements of the array. Next line contains an integer k denoting the number such that elements less than and equal to k are group together. 

Output:
For each test case, the output is an integer displaying the minimum swaps required.

Constraints:
1<=T<=100
1<=n<=50

Example:
Input
2
5
2 1 5 6 3
3
7
2 7 9 5 8 7 4
6
Output
1
2

Explanation:
1. To bring elements 2, 1, 3 together, swap element '5' with '3' such that final array will be- arr[] = {2, 1, 3, 6, 5}
2. To bring elements 2, 5, 4 together, swap element 7 with 5 & 9 with 4 such that the final array will be {2,5,4,7,8,7,9} 


*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        int a[n],k;
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        cin>>k;
        int noe_lt_k=0,c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<=k)
                noe_lt_k++;
        }
        //first_sliding_window
         for(int i=0;i<noe_lt_k;i++)
        {
            if(a[i]>k)
                c++;
        }
        
        
        int swap_count=c;
//use sliding_window_technique 
//set i to the start of prev sliding window...in the new sliding window that element will be excluded...y marks the end of the new sliding window...that is new element included
//Hence, if the ele marked by i is greater than k, then swap_count can be decreased and if ele marked by y is greater than k, then swao_count is increased
//min of new sliding window swap_count and old sliding window swap count is stored 
       for(int i=0,y=noe_lt_k; y<n; i++,y++)
       {
           if(a[i]>k)
            c--;
           
           if(a[y]>k)
           c++;
           
           swap_count=min(swap_count,c);
           
       }
        
        cout<<swap_count<<endl;
        
    }
    
    
    return 0;
}
