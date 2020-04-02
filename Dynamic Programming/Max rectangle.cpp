//Phoenix_RK
/*

Given a binary matrix, Your task is to complete the function maxArea which the maximum size rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .


For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8


***************************************
Reference : https://www.youtube.com/watch?v=g8bSdXCG-lA
***************************************
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends
/*You are required to complete this method*/
int max(int a,int b)
{
    return a>b?a:b;
}
int find_area(int a[],int n)
{
    stack<int> s;
    int area=0,max_area=0,i;
    for(i=0;i<n;)
    {
        if(s.empty() || a[s.top()]<=a[i])
            {
                s.push(i);
                i++;
            }
        else
        {
            
                int t=s.top();
                s.pop();
                if(!s.empty())
                {
                    area=a[t]*(i-s.top()-1);
                  
                }
                else
                  area=a[t]*i;
                
               max_area=max(area,max_area);
        }
        
    }
    
     while(!s.empty())
    {
        int t=s.top();
        s.pop();
         if(!s.empty())
        {
            area=a[t]*(i-s.top()-1);
          
        }
        else
           area=a[t]*i;
        
        max_area=max(area,max_area);
    }
 
    return max_area;
    
    
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    
    int a[m],max_area=0;
    memset(a,0,sizeof(a));
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==0)
            {
                a[j] =0;  
            }
            else
                a[j]++;
        }
        
      max_area=max(max_area,find_area(a,m));
    }
    
    return max_area;
    
    
    
}

