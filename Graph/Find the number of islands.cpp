//Phoenix_RK
/*

A group of connected 1's forms an island. The task is to complete the method findIslands() which returns the number of islands present. The function takes three arguments the first is the boolean matrix A and then the next two arguments are N and M denoting the size(N*M) of the matrix A .

*/
int findIslands(vector<int> A[], int N, int M);

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
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

void dfs(vector<int>A[],int i,int j,int N,int M)
{
    if(i<0 || i>=N || j<0 || j>=M || A[i][j]==0)
    return;
    
    A[i][j]=0;
/*  
    4 7
0 1 1 1 
0 0 1 1
0 1 0 1
1 0 0 0
0 0 1 0
1 1 0 0
0 1 1 1
  */  
 
    dfs(A,i+1,j,N,M);//top
    dfs(A,i-1,j,N,M);//bottom
    dfs(A,i,j+1,N,M);//right
    dfs(A,i,j-1,N,M);//left
    dfs(A,i+1,j+1,N,M);//dia down right
    dfs(A,i-1,j-1,N,M);//dia up left
    dfs(A,i+1,j-1,N,M);//dia down left
    dfs(A,i-1,j+1,N,M);//dia up right
    
    
}
int findIslands(vector<int> A[], int N, int M) {


    // Your code here
    int count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
         //   cout<<A[i][j]<<" ";
            if(A[i][j]==1)
            {
                count++;
                dfs(A,i,j,N,M);
            }
        }
    }
    
    return count;
   
    
}

