//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/generate-grey-code-sequences/1


Given a number N, your task is to complete the function which generates all n-bit grey code sequences, a grey code sequence is a sequence such that successive patterns in it differ by one bit.

Example 1:

Input:
N = 2
Output: 00 01 11 10
Explanation: All 2-bit gray codes are
00, 01, 11, 10 such that successive
patterns in it differ by one bit.
Example 2:

Input:
N = 1
Output: 0 1
 

Your Task:
Complete the function generateCode() which takes an integer as input parameter and retruns an array of all N bit grey code sequence such that successive patterns in it differ by one bit.

Expected Time Complexity: O(N * log N)
Expected Auxiliary Space: O(1)

Constraints:
1<=N<=10
*/


vector <string> generateCode(int N)
{
     //Your code here
     
    vector<string> arr;
     if(N==0)
        return arr;
    
    arr.push_back("0");
    arr.push_back("1");
    
    int i,j;
    for(i=2;i<(1<<N);i=i<<1)
    {
        
        for(j=i-1;j>=0;j--)
            arr.push_back(arr[j]);
            
        for(j=0;j<i;j++)
            arr[j]="0"+arr[j];
            
        for(j=i;j<2*i;j++)
            arr[j]="1"+arr[j];
    }
    
    return arr;
}
