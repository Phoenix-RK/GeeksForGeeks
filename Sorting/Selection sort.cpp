//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/selection-sort/1

****************************************************************
In selection sort, the smallest element or the largest element is fixed at the position
similarly, in every iteration, the nth smallest or the nth largest element is fixed at its position

Therefore, at any point, there is two types of arrays
1)sorted subarray 2)unsorted subarray

The task is to complete select() function which is used to implement Selection Sort.

Input:
First line of the input denotes number of test cases 'T'. First line of the test case is the size of array and second line consists of array elements.

Output:
Sorted array in increasing order is displayed to the user.

Your Task :
Complete the function select() that helps to sort the array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=arr[i]<= 1000

Example:

Input:
2
5
4 1 3 9 7
10
10 9 8 7 6 5 4 3 2 1

Output:
1 3 4 7 9
1 2 3 4 5 6 7 8 9 10

Explanation : Sorted array is 1,3,4,7,9
*/

// C program for implementation of Bubble sort
#include <stdio.h>
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int select(int arr[], int i);
 
// A function to implement bubble sort
void selectionSort(int arr[], int n)
{
   int i, j;
   for (i = n-1; i >=0; i--)      
   {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
   }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}// } Driver Code Ends


/* The task is to complete select() which is used 
   as shown below to implement selectionSort() 
 
A function to implement selection sort
void selectionSort(int arr[], int n) {
   int i, j;
   for (i = n-1; i >=0; i--)     {
        int j = select(arr, i);
        swap(&arr[i], &arr[j]);
   }
}  */

int select(int a[], int i)
{
    // Your code here 
     int max_ele=-999;
    int ind=i;
    for(int j=0;j<i;j++)
    {
        if(a[j]>a[i])
        {
            
           if(max_ele<a[j])
           {
               max_ele=a[j];
               ind=j;
            }
            
        }
    }
    return ind;
}

