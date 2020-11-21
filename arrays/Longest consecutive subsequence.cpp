//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#


Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output: 6
Explanation: The consecutive numbers 
here are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output: 4
Explanation: 1, 2, 3, 4 is the longest
consecutive subsequence.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
0 <= a[i] <= 105

*/


// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int nums[], int N)
{
  //Your code here

  int len=1,max_len=1;
  
  sort(nums,nums+N);
  
  for(int i=1;i<N;i++)
  {
      if(nums[i]!=nums[i-1])
      {
          if(nums[i]==nums[i-1]+1)
          {
              len++;
          }
          else
          {
              max_len=max(max_len,len);
              len=1;
          }
      }
  }
  
  return max(max_len,len);
}


/*      
        if(N<=1)
            return N;
       
        map <int,int> m;
        int len=0,r;
        for(int i=0;i<N;i++)
        {
            if(m[nums[i]])
                continue;
            
            if(m.find(nums[i]-1)==m.end() && m.find(nums[i]+1)==m.end())
            {
                m[nums[i]]=1;
                len= max(len,m[nums[i]]);
                continue;
            }
            
            if(m.find(nums[i]+1)==m.end())
            {
                r = m[nums[i]]  = m[nums[i]-m[nums[i]-1]]= m[nums[i]-1]+1;
                len =  max(r, len);
                continue;
                
            }
            
            if(m.find(nums[i]-1)==m.end())
            {
                r = m[nums[i]] = m[nums[i]+m[nums[i]+1]] = m[nums[i]+1] +1;
                len =  max(r, len);
                continue;
            }
           
                r= m[nums[i]] = m[nums[i]-m[nums[i]-1]] = m[nums[i]+ m[nums[i]+1]] = m[nums[i]-1] + m[nums[i]+1] + 1;
                len=max(r,len);
            
            
        }
        
        
        return len;
  */
