//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#

Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.




*/


bool subArrayExists(int arr[], int n)
{
    //Your code here

    unordered_set<int> m;
    int j=0,sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        
       if(sum==0 || m.find(sum)!=m.end()) //if the sum is 0 or if the current sum has already been seen it means a subarray is with 0 sum
            return true;
      
        m.insert(sum);
        
    }
    
    
    
    return false;
    
}


  /*
        
        eg: 4 2 -3 1 6
        
        in corresponding iter
           
           sum produced will be 
           4 6 3 4 
           
           so here in 4 th iteration sum=4, which has already been encountered , it means a subarray is with 0 sum
        
        
        */
        


