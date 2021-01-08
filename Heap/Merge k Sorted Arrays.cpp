//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1#

Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
Example 2:

Input:
K = 4
arr[][]={{1,2,3,4}{2,2,3,4},
         {5,5,6,6},{7,8,9,9}}
Output:
1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted
arrays of size 4, 4, 4, 4
arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4],
[5, 5, 6, 6]  [7, 8, 9, 9 ]]
The merged list will be 
[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 
6, 6, 7, 8, 9, 9 ].
Your Task:
You need to complete mergeKArrays() function which takes 2 arguments, an arr[k][k] 2D Matrix containing k sorted arrays and an integer k denoting the number of sorted arrays. The function should return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList<Integer> in java, and list in python)

Expected Time Complexity: O(nk Logk)
Expected Auxiliary Space: O(k)

Note: This space is required for returning the resulted sorted array, other work should be done in O(K) Auxiliary Space.

Constraints:
1 <= K <= 100

*/




// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
typedef pair<int,pair<int,int>> store;
int *mergeKArrays(int arr[][N], int k)
{
//code here
   int* res=new int[k*k];
   priority_queue<store,vector<store>,greater<store>> pq;
   
   for(int i =0; i<k ;i++)
   {
        pq.push({arr[i][0],{i,0}});
   }
    int ind=0;
   while(!pq.empty())
   {
       store s=pq.top();
       pq.pop();
       res[ind++]=s.first;
       int arr_ind = s.second.first;
       int ele_ind = s.second.second;
       
       if(ele_ind+1<k)
        pq.push({arr[arr_ind][ele_ind+1],{arr_ind,ele_ind+1}});
       
   }
   
   return res;

}




