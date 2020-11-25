//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#



You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output: 113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.
Example 2:

Input:
N = 3
A[] = {15,17,20}
M = 2
Output: 32
Explanation: Allocation is done as 
{15,17} and {20}
Your Task:
Complete findPages() function that takes a, n, and m as arguments and returns the expected answer.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 105
1 <= A [ i ] <= 106
1 <= M <= 105

*/


//User function template in C++

int max(int a,int b)
{
    return a>b?a:b;
}
bool valid(int arr[],int  n,int  k,int  mid)
{
    int curr=0,count=1;
    for(int i=0;i<n;i++)
    {
        if(curr+arr[i]>mid)
        {
            curr=arr[i];
            count++;
            if(count>k)
                return false;
        }
        else
            curr+=arr[i];
    }
    return true;
    
}

int findPages(int *arr, int n, int m) {
    //code here
    if(n<m)
        return -1;
    int sum=0,max_ele=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        max_ele=max(max_ele,arr[i]); //each student will read atleast one book and the book with max no of pages is the starting pt
    }
    
    int start=max_ele,end=sum,ans=0;
    
    while(start<=end)
    {
         int mid=(start+end)/2;
        
        if(valid(arr,n,m,mid))
        {
            ans=mid;
            end=mid-1;
            
        }
        else
        {
            start=mid+1;
            
        }
    }
    return ans;
}



