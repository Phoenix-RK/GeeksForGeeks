//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1



Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.

Example 1:

Input:
N = 5
A[] = {1,2,1,1,3}
Output: 1
Explanation: a sub-sequence 1 2 3 exist.
Example 2:

Input:
N = 3
A[] = {1,1,3}
Output: 0
Explanation: no such sub-sequence exist.
Your Task:
Your task is to complete the function find3Numbers which finds any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. You need to return them as a vector/ArrayList/array (depending on the language cpp/Java/Python), if no such element is present then return the empty vector of size 0.

Note: The output will be 1 if the sub-sequence returned by the function is present in array A else 0. If the sub-sequence returned by the function is not in the format as mentioned then the output will be -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 105
1 <= A[i] <= 106, for each valid i

*/



/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> a, int N) {
    // Your code here
    vector<int> res;
   int dec[N],inc[N];
   inc[0]=-1; 
   dec[N-1]=-1;
   int min=0;
   
   //keep track of prev lowest element than a[i]
   for(int i=1;i<N;i++)
   {
       if(a[i]<=a[min])
       {
           inc[i]=-1;
           min=i;
       }
       else
        inc[i]=min;
   }
   
   /*
   for(int i=0;i<N;i++)
    cout<<inc[i]<<" ";
    cout<<endl;
    */
    
    
   int max=N-1;
   //keep track of next element greater than a[i]
   for(int i=N-2;i>=0;i--)
   {
       if(a[i]>=a[max])
       {
           dec[i]=-1;
           max=i;
       }
       else
        dec[i]=max;
   }
   /*
 for(int i=0;i<N;i++)
    cout<<dec[i]<<" ";
    cout<<endl;
    */
   for(int i=0;i<N;i++)
   {
       if(inc[i]!=-1 && dec[i]!=-1)
       {
           res.push_back(a[inc[i]]);
           res.push_back(a[i]);
           res.push_back(a[dec[i]]);
           return res;
       }
   }
    return res;
}
