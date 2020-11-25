//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#




Given an array A[] of size N, construct a Product Array P (of same size N) such that P[i] is equal to the product of all the elements of A except A[i].

 

Example 1:

Input:
N = 5
A[] = {10, 3, 5, 6, 2}
Output: 180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
 

Example 2:

Input:
N = 2
A[] = {12,0}
Output: 0 12


Your Task:
You do not have to read input. Your task is to complete the function productExceptSelf() that takes array A[] and N as input parameters and returns a list of N integers denoting the product array P. If the array has only one element the returned list should should contains one value i.e {1}
Note: Try to solve this problem without using the division operation.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

 

Constraints:
1 <= N <= 1000
0 <= Ai <= 200
Array may contain duplicates.

*/

//O(n^2)
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here 
   
    long long  prod=1;
    vector<long long int> res(n);
    for(int i=0;i<n;i++)
    {
        prod=1;
        for(int j=0;j<n;j++)
        {
            if(j==i)
                continue;
            
            prod*=nums[j];
            if(prod==0)
                break;
        }
        
        res[i]=prod;
    }
    return res;
}


//O(n)

vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here 
    int flag=0;
    long long  prod=1;
    vector<long long int> res(n);
   
    for(int i=0;i<n;i++)
    {
        
        if(nums[i]==0)
            flag++;
        else
            prod*=nums[i];
    }
    
    
    for(int i=0;i<n;i++)
    {
        if(nums[i]==0 && flag>1)
            res[i]=0;
        else if(nums[i]==0)
            res[i]=prod;
        else if(nums[i]!=0 && flag>=1)
            res[i]=0;
        else
            res[i]=prod/nums[i];
    }
    return res;
  
}


