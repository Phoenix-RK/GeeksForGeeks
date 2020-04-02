//Phoenix_RK
/*
Given an array arr[] of N integers arranged in a circular fashion. Your task is to find the maximum contigious subarray sum.

Input:
3
7
8 -8 9 -9 10 -11 12
8
10 -3 -4 7 6 5 -4 -1
8
-1 40 -14 7 6 5 -4 -1

Output:
22 (10 -11 12) - kadane
23  ( 7 6 5 -4 -1 10) sum - min_so_far(-3-4) 
52  (7 6 5 -4 -1 -1 40) sum - min_so_far(-14)

*/

#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
return a>b?a:b;
}
int min(int a,int b)
{
return a<b?a:b;
}
int main()
 {
	//code
    int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        
	    int curr_max=a[0],curr_min=a[0],max_so_far=a[0],min_so_far=a[0],sum=a[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        curr_max=max(curr_max+a[i],a[i]);
	        max_so_far=max(max_so_far,curr_max);
	        curr_min=min(curr_min+a[i],a[i]);
	        min_so_far=min(min_so_far,curr_min);
	        sum+=a[i];
	    }
	    if(min_so_far==sum)//if suppose all ele are -ve, then return negative ele that is greter than others 
	        cout<<max_so_far<<endl;
	    else
	         cout<<max(sum-min_so_far,max_so_far)<<endl; // check if contiguos sum is intervened by some negative ele 2 3 -6 -7 4 5  ..if so return arr_sum-neg_sum 
	         //else return ans from kadanes algo  2 3 4 5 -6 -7 
	    
	
	}
	return 0;
}
