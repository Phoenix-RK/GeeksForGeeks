//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/heap-sort/1

Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.

Example 1:

Input:
N = 5
arr[] = {4,1,3,9,7}
Output:1 3 4 7 9
Explanation:After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.
Example 2:

Input:
N = 10
arr[] = {10,9,8,7,6,5,4,3,2,1}
Output:1 2 3 4 5 6 7 8 9 10
Explanation:After sorting elements
using heap sort, elements will be
in order as 1, 2,3,4,5,6,7,8,9,10.
Your Task :
Complete the functions heapify() and buildheap().

Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
1 <= arr[i] <= 106
*/


/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()
void heapify(int arr[], int n, int i)  {
      // Your Code Here
      
      int largest=i;
      int left = 2*i + 1;
      int right= 2*i + 2;
      
      if(left<n && arr[left]>arr[largest])
        largest=left;
    
      if(right<n && arr[right]>arr[largest])
        largest=right;
        
     if(largest!=i)
     {
         swap(arr[i],arr[largest]);
         
         heapify(arr,n,largest);
     }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for(int i=(n-1)/2 ; i>=0;i--)
        heapify(arr,n,i);
}



