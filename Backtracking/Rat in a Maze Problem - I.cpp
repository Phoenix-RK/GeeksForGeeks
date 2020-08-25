//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

Consider a rat placed at (0, 0) in a square matrix of order N*N. It has to reach the destination at (N-1, N-1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and cannot be crossed while value 1 at a cell in the matrix represents that it can be traveled through.

Example 1:

Input: N = 4, m[][] = {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}}
Output: DDRDRR DRDDRR
Explanation: The rat can reach the 
destination at (3, 3) from (0, 0) by two 
paths ie DRDDRR and DDRDRR when printed 
in sorted order we get DDRDRR DRDDRR.
Example 2:
Input: N = 2, m[][] = {{1, 0},
                       {1, 0}}
Output: -1
Explanation: No path exits

Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2d array m[][] as input parameters and returns a list of paths.
 
Note:  In case of no path, return an empty list. The driver will output -1 automatically.

Expected Time Complexity: O((N2)4).
Expected Auxiliary Space: O(L*X), L = length of the path, X = number of paths.
*/


#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
bool issafe(int i,int j,int n,int m[MAX][MAX],bool is_visited[MAX][MAX])
{
    return i >= 0 and i < n and j >= 0 and j < n and is_visited[i][j] == false and m[i][j] == 1;
}
void solve(int i,int j,int n,int m[MAX][MAX],bool is_visited[MAX][MAX],string s,vector<string>& v)
{
    if(i==n-1&&j==n-1)
    {
        if(m[i][j]==1)
            v.push_back(s);
        is_visited[i][j]=false;
        return;
    }
    
    if(issafe(i,j,n,m,is_visited))
    {
        is_visited[i][j]=true;
        
        s.push_back('D');
        solve(i+1,j,n,m,is_visited,s,v);
        s.pop_back();
        
        
        s.push_back('L');
        solve(i,j-1,n,m,is_visited,s,v);
        s.pop_back();
        
        s.push_back('R');
        solve(i,j+1,n,m,is_visited,s,v);
        s.pop_back();
        
        
        s.push_back('U');
        solve(i-1,j,n,m,is_visited,s,v);
        s.pop_back();
           
        is_visited[i][j]=false;
    }
    return;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    bool is_visited[MAX][MAX];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            is_visited[i][j]=false;
        }
    }
    
    vector<string> v;
    string s="";
    solve(0,0,n,m,is_visited,s,v);
    return v;
    
}

