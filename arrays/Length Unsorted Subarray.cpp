//Phoenix_RK

/*

Given an unsorted array A of size N. Find the subarray A[s..e] such that sorting this subarray makes the whole array sorted.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the size of array. The second line of each test case contains N elements.

Output:
Print the starting and ending index(0-based indexing) of subarray A[s..e]. If no such subarray exists, print 0 for starting index and 0 for ending index.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ C[i] ≤ 108

Example:
Input:
2
11
10 12 20 30 25 40 32 31 35 50 60
9
0 1 15 25 6 7 30 40 50

Output:
3 8
2 5

*****************************************************
Find the subarray which is unsorted
1)scan from the left and find the point at which the order collapses
2)scan from the right and the find the point at which the order collapses
3)Find the min and max element in the range of the unsorted subarray
4) Check if every element to the left of the subarray is less than min of the subarray. If not, extend the left range of the subarray to the break point.
5)Check from the right if every element in the right of the subarray is greater than max of the subarray. If not, extend the right range of the subarray to that break point



*/


#include<bits/stdc++.h>
using namespace std;
  int min(int a,int b)
   {
        return a<b?a:b;
   }
    
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
	    int n;
    	cin>>n;
    	int nums[n];
    	for(int i=0;i<n;i++)
    	    cin>>nums[i];
    	    
        int l=0,r=0;
        int i=1,j=n-1;
        while(i<n && nums[i]>=nums[i-1])
            i++;
        
        if(i==n)
        {
            cout<<"0 0"<<endl;
            continue;
        }
        
        i--;
        
        while(j>=0 && nums[j]>=nums[j-1])
            j--;
        
        int min_e=INT_MAX,max_e=INT_MIN;
        for(int k=i;k<=j;k++)
        {
            min_e=min(nums[k],min_e);
            max_e=max(nums[k],max_e);
        }
        l=i;
        r=j;
        for(int k=0;k<i;k++)
        {
            if(nums[k]>min_e)
            {
                l=k;
                break;
            }
        }
        
        for(int k=n-1;k>=j;k--)
        {
            if(nums[k]<max_e)
            {
                r=k;
                break;
            }
        }
      
        if(r-l<0)
            cout<<"0"<<endl;
        else
            cout<<l<<" "<<r<<endl;
	
	}
	return 0;
}
