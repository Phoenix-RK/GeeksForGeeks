//Phoenix_RK



/*


https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#

Given an array Arr that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is  6, -3, -10 which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is 2, 3, 4, 5 which gives product as 120.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxProduct() which takes the array of integers arr and n as parameters and returns an integer denoting the answer.
Note: Use 64-bit integer data type to avoid overflow.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 500
-102 <= Arri <= 102
*/


#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long  maxProduct(int *arr, int n) {
	    // code here
	    
	    int128_t current_max= arr[0] ,current_min = arr[0] , final_max= arr[0];
        
        for(long long i=1;i<n;i++)
        {
            int128_t temp=current_max;
            int128_t x =arr[i];
            current_max= max(x,max(temp*x,current_min*x));
            current_min= min(x,min(temp*x,current_min*x));

            if(current_max>final_max)
            {
                final_max=current_max;
            }
            
        }
        return (long long)final_max;
	    
	}
	
};
