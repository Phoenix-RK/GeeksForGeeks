//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/sum-of-fai-aj-over-all-pairs-in-an-array-of-n-integers/0/


Given an array A of n integers, find the sum of f(a[i], a[j]) of all pairs (i, j) such that (1 <= i < j <= n).
f(a[i], a[j]):       If | a[j]-a[i] | > 1

                         f(a[i], a[j]) = a[j] - a[i]

                         Else  if | a[j]-a[i] | <= 1

                         f(a[i], a[j]) = 0

Input:
The first line of the input contains T denoting the number of test cases. For each test case, the first line contains integer n denoting the size of the array A, followed by n space separated integers denoting the element of array A.

Output:
For each test case, the output is an integer denoting the sumof f(a[i],a[j]) of all pairs. 

Constraints:
1<=T<=100
1<=n<=50

Example:
Input:
2
4
6 6 4 4
5
1 2 3 1 3
Output:
-8
4

Explanation:
1. All pairs are: (6 - 6) + (4 - 6) + (4 - 6) + (4 - 6) + (4 - 6) + (4 - 4) = -8
2. The pairs that add up are: (3, 1), (3, 1) to give 4, rest all pairs according to condition gives 0.

*/

//Phoenix_RK
#include <bits/stdc++.h>
using namespace std;

//O(n^2)
int main() 
{

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++) 
            cin>>arr[i];
            
        int sum=0;
        
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(arr[j]-arr[i])>1)
                    sum+=(arr[j]-arr[i]);
               
            }
        }/*
        unordered_map<int, int> cnt;
        int ans = 0, pre_sum = 0;
        for (int i = 0; i < n; i++) 
        {
            ans += (i * arr[i]) - pre_sum;
            pre_sum += arr[i];
    
            if (cnt[arr[i] - 1])
                ans -= cnt[arr[i] - 1];
                
            if (cnt[arr[i] + 1])
                ans += cnt[arr[i] + 1];
    
            cnt[arr[i]]++;
        }
        
        cout<<ans<<endl; 
        */
        cout<<sum<<endl;
    }
    
}
//O(n)

/*



i=0
    ans = ans+(0*6)-0 =0
    pre_sum=pre_sum+arr[i] = 6
    cnt  6 - 1
i=1
    ans = 0 + (1*6) - 6 =0
    pre_sum=6+6 = 12
    cnt 6 - 2
    
i=2
    ans=0+(2*4)-12=-4
    pre_sum=16
    
i=3
    ans=-4+(3*4)-16=-8
    pre_sum=20

[a1,a2,a3,a4]

(a2-a1)+(a3-a1)+(a4-a1)+(a3-a2)+(a4-a2)+(a4-a3)
= a2+2*a3+3*a4-(a1+a2+a3+a1+a2+a1)
= ((3*a4) - (a1+a2+a3)) + ((2*a3)-(a1+a2)) +(a2-(a1))
= summation((i*a[i])-(sum_so_far)) where i range from 0 to n-1
*/


int main() 
{

    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++) 
            cin>>arr[i];
            
     
        map<int, int> cnt;
        int ans = 0, pre_sum = 0;
        for (int i = 0; i < n; i++) 
        {
            ans += (i * arr[i]) - pre_sum;
            pre_sum += arr[i];
    
            if (cnt[arr[i] - 1])
                ans -= cnt[arr[i] - 1];
                
            if (cnt[arr[i] + 1])
                ans += cnt[arr[i] + 1];
    
            cnt[arr[i]]++;
        }
        
        cout<<ans<<endl; 
     
    }
    
}



