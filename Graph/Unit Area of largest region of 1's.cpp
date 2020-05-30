//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0

Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.



*/

#include<bits/stdc++.h>
using namespace std;

int findArea(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findArea(A, N, M) << endl;
    }
    return 0;
}

void dfs(vector<int>A[],int i,int j,int N,int M,int& count)
{
    if(i<0 || i>=N || j<0 || j>=M || A[i][j]==0)
    return;
    count++;
    A[i][j]=0;

 
    dfs(A,i+1,j,N,M,count);//top
    dfs(A,i-1,j,N,M,count);//bottom
    dfs(A,i,j+1,N,M,count);//right
    dfs(A,i,j-1,N,M,count);//left
    dfs(A,i+1,j+1,N,M,count);//dia down right
    dfs(A,i-1,j-1,N,M,count);//dia up left
    dfs(A,i+1,j-1,N,M,count);//dia down left
    dfs(A,i-1,j+1,N,M,count);//dia up right
    
    
}
int max(int a,int b)
{
    return a>b?a:b;
}
int findArea(vector<int> A[], int N, int M) {


    // Your code here
    int max_count=-99;
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
         //   cout<<A[i][j]<<" ";
            if(A[i][j]==1)
            {
                count=0;
                dfs(A,i,j,N,M,count);
                max_count=max(max_count,count);
            }
        }
    }
    
    return max_count;
   
    
}

