//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1#


Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.

Example 1:

Input: 
N = 9
Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
Output: 9 -2 4 -1 5 -5 0 -3 2
Example 2:

Input: 
N = 10
Arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
Output: -5 5 -2 2 -8 4 7 1 8 0 
Your Task:  
You don't need to read input or print anything. Your task is to complete the function rearrange() which takes the array of integers arr[] and n as parameters. You need to modify the array itself.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
Note: Array should start with positive number.

Constraints:
1 ≤ N ≤ 107
-106 ≤ Arr[i] ≤ 107


O(1) space complexity

find the first out of place element in the remaining unprocessed array. An element is out of place if it is negative and at odd index, or it is positive and at even index. Once we find an out of place element, we find the first element after it with opposite sign. We right rotate the subarray between these two elements (including these two).



O(n) space complexity

Have two arrays for positive n negative elements

*/

//User function template for C++
class Solution{
public:
    void reverse(int arr[],int start,int end)
    {
        while(start<end)
        {
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        
    }
	void rearrange(int arr[], int n) {
	    // code here
	    
	    /*
	    Input:  arr[] = {1, 2, 3, -4, -1, 4}
	    
	                    -4 1 2 3 -1 4
	                    -4 1 -1 2 3 4
	                    
Output: arr[] = {-4, 1, -1, 2, 3, 4}
	 */
	 /*
	    int mis=-1;
	    for(int i=0;i<n;i++)
	    {
	            
	            
	       if(mis>=0)
	       {
	           if((arr[i]>=0 && arr[mis]<0) || (arr[i]<0 && arr[mis]>=0))
	           {
	               reverse(arr,mis,i-1);
	               reverse(arr,mis,i);
	           
	           if(i-mis>=2)
	            mis+=2;
	           else
	            mis=-1;
	           }
	       }
	        
	        if(mis==-1)
	        {
	            if( (arr[i]>=0 && (i%2!=0)) || (arr[i]<0 && (i%2==0)))
	                mis=i;
	        }
	    }
	    */
	    vector<int> pos;
	    vector<int> neg;
	    int i,j,k;
	    for(i=0;i<n;i++)
	    {
	        if(arr[i] >= 0)
	          pos.push_back(arr[i]);
	        else
	          neg.push_back(arr[i]);
	    }
	    i=0;
	    j=0;
	    k=0;
	    while(i < pos.size() and j < neg.size())
	    {
	        arr[k++]=pos[i++];
	        arr[k++]=neg[j++];
	    }
	    while(j < neg.size())
	    {
	        arr[k++]=neg[j++];
	    }
	    while(i < pos.size())
	    {
	        arr[k++]=pos[i++];
	    }
	    
	}
};
