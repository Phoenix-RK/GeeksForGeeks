//Phoenix_RK


/*

https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/

Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray within the array of numbers which has negative and positive numbers.

Examples:


Input: a[] = {20, -5, -1} 
         k = 3
Output: 14
Explanation: All sum of contiguous 
subarrays are (20, 15, 14, -5, -6, -1) 
so the 3rd largest sum is 14.

Input: a[] = {10, -10, 20, -40} 
         k = 6
Output: -10 
Explanation: The 6th largest sum among 
sum of all contiguous subarrays is -10.

*/


int kthLargest(vector<int> a,int k)
{
	int sum[a.sixe()+1];
	sum[0]=0;
	sum[1]=a[0];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i-1];	
	}

	priority_queue<int,vector<int>,greater<int>> pq; //min_heap
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int curr_subSum=sum[j]-sum[i-1]; //contiguous subarray sum from i to j index can be calc as sum[j]-sum[i-1]..this is because say i=2 and j=3 then sum[j]=a1+a2+a3 and sum[i-1]=a1...therefore sum[j]-sum[i-1]=a1+a2+a3-a1=a2+a3
			if(pq.size()<k)
				pq.push(curr_subSum);
			else if(pq.top()<curr_subSum)
			{
				pq.pop(); 
				pq.push(curr_subSum);
			}
		}
	}
	
	return pq.top();

}

