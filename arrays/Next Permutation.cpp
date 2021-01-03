//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/next-permutation/0#

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers. If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

For example:
1,2,3 → 1,3,2
3,2,1 → 1,2,3

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N depicting the size of array and next line followed by the value of array.

Output:
Print the array of next permutation in a separate line.

Constraints:
1 ≤ T ≤ 40
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100

Example:
Input:
1
6
1 2 3 6 5 4

Output:
1 2 4 3 5 6
*/


//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
void reverse(int s[],int start,int end)
{
    while(start<end)
    {
        int temp=s[start];
        s[start]=s[end];
        s[end]=temp;
        
        start++;
        end--;
        
    }
    
    
}
void nextPermutation(int s[],int n)
{
    int i=n-2;
    while(i>=0 && s[i]>=s[i+1])
        i--;
    if(i==-1)
    {
        reverse(s,0,n-1);
        return;
    }
    
    for(int j=n-1;j>i;j--)
    {
        if(s[j]>s[i])
        {
            int temp=s[j];
            s[j]=s[i];
            s[i]=temp;
            break;
        }
    }
    
    reverse(s,i+1,n-1);
    
    
}
int main()
{
    int T;
    
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        
        int s[n];
        for(int i=0;i<n;i++)
            cin>>s[i];
        
        nextPermutation(s,n);
        for(int i=0;i<n;i++)
            cout<<s[i]<<" ";
            
        cout<<endl;
        
    }
    
    
    return 0;
}
