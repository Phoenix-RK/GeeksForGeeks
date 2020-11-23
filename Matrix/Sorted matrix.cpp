//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/sorted-matrix/0#



Given an n x n matrix, where every row and column is sorted in non-decreasing order. Print all elements of matrix in sorted order.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer n denoting the size of the matrix. Then the next line contains the n x n elements in row wise order.

Output:
Print the elements of the matrix in sorted order.

Constraints:
1<=T<=100
1<=n<=100
1<=a[n][n]<=100

Example:
Input:
2
4
10 20 30 40 15 25 35 45 27 29 37 48 32 33 39 50
3
1 3 4 2 6 7 5 8 9

Output:
10 15 20 25 27 29 30 32 33 35 37 39 40 45 48 50 
1 2 3 4 5 6 7 8 9 

*/

//Method1: Young Tableau

#include<bits/stdc++.h>
using namespace std;

void adjust(vector<vector<int>>& ans,int i,int j)
{
    int down=(i+1 < ans.size())?ans[i+1][j]:INT_MAX;
    int right=(j+1< ans.size())?ans[i][j+1]:INT_MAX;
    
    if(down==INT_MAX && right==INT_MAX)
        return ;
    if(down<right)
    {
        ans[i][j]=down;
        ans[i+1][j]=INT_MAX;
        adjust(ans,i+1,j);
    }
    else
    {
        ans[i][j]=right;
        ans[i][j+1]=INT_MAX;
        adjust(ans,i,j+1);
    }
}
int extract_min(vector<vector<int>>& ans)
{
    int x=ans[0][0];
    ans[0][0]=INT_MAX;
    adjust(ans,0,0);
    return x;
}
int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>ans[i][j];
        }
        
        for(int i=0;i<n*n;i++)
        {
            cout<<extract_min(ans)<<" ";
          
        }
        cout<<endl;
    }
    
    
    return 0;
}


//Method 2:Heap



int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        
        priority_queue<int,vector<int>,greater<int>> p;
        int x;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                p.push(x);
            }
        }
           
        
        while(!p.empty())
        {
            cout<<p.top()<<" ";
            p.pop();
        }
        cout<<endl;
    }
    
    
    return 0;
}
