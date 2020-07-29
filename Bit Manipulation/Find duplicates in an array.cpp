//Phoenix_RK

/*
Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N which denotes the number of elements in the array. The second line of each test case contains n space separated integers denoting elements of the array a[].

Output:
Print the duplicate elements from the given array. The order of the output should be in sorted order. Print -1 if no duplicate exists.

Your Task:
Complete the function duplicates() which takes array a[] and n as input as parameters and returns a list of elements that occur more than once in the given array in sorted manner. If no such element is found return -1. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Note : The extra space is only for the array to be returned.
Try and perform all operation withing the provided array. 

Constraints:
1 <= T <= 100
1 <= N <= 105
0 <= A[i] <= N-1, for each valid i

Example:
Sample Input:
2
4
0 3 1 2
5
2 3 1 2 3 

Sample Output:
-1
2 3 

Explanation:
Testcase 1: N=4 and all elements from 0 to (N-1 = 3) are present in the given array. Therefore output is -1.
Testcase 2: 2 and 3 occur more than once in the given array.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
Method 1 - TLE
vector<int> duplicates(int a[], int n) {
    // code here
    
    map <int,int> m;
    vector<int> output;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
        if(m[a[i]]==2)
        {
            flag=1;
            output.push_back(a[i]);
        }
        
    }
    if(flag==0)
        output.push_back(-1);
    
    sort(output.begin(), output.end());
    return output;

}
*/
/*

Method 2- if element is present more than twice it prints extra
vector<int> duplicates(int a[], int n) {
    
    vector<int> output;
    int flag=0;
    for(int i=0;i<n ;i++)
    {
        if(a[abs(a[i])]>=0)
        {
            a[abs(a[i])]=-a[abs(a[i])];
            
        }
        else
        {
            flag=1;
            output.push_back(abs(a[i]));
        }
            
    }
    
    if(flag==0)
        output.push_back(-1);
    
    sort(output.begin(), output.end());

    return output;
    
}*/

//Method 3 

vector<int> duplicates(int a[], int n) {
    
    vector<int> output;
    int flag=0;
    for(int i=0;i<n ;i++)
    {
       a[ a[i]%n ]+=n;
       
       if(a[ a[i]%n ]/n==2)
        {
            flag=1;
            output.push_back(a[i]%n);
            
        }
    }
    
    if(flag==0)
        output.push_back(-1);
    
    sort(output.begin(), output.end());

    return output;
    
}

