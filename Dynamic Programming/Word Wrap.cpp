//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/word-wrap/0#



Given an array of size N, which denotes the number of characters in one word. The task is simple, count the number of words in a single line with space character between two words.

Input:
First line contains the number of test cases T. First line of every test case consists of N, denoting number of elements in array. Second line consists of elements in array. Third line consists of characters allowed per line.

Output:
Single line output,print 2*L spaced integers (where L is the number of lines required to adjust the words with given limit of character per line), denoting from which word to word in every line.(for more clearance of output, look the output in example).

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
4
3 2 2 5
6
3
3 2 2
4
Output:
1 1 2 3 4 4 
1 1 2 2 3 3 

For the first test case.
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4 





*/


#include<bits/stdc++.h>
using namespace std;
 
  
void printSolution (int p[], int n)  
{  
    if (p[n] == 1)  
        cout<<p[n]<<" "<<n<<" ";
    else{
        printSolution (p, p[n]-1) ;  
        cout<<p[n]<<" "<<n<<" ";
    
    }
} 

void solveWordWrap(int a[],int n,int W)
{
    int space[n+1][n+1];
    int ls[n+1][n+1];
    int c[n+1];
    int p[n+1];
 
    for(int i=1;i<=n;i++)
    {
        space[i][i]=W-a[i];
        for(int j=i+1;j<=n;j++)
            space[i][j] = space[i][j-1] - a[j] -1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(space[i][j]<0)
                ls[i][j]=INT_MAX;
            else if(j==n && space[i][j]>=0)
                ls[i][j] = 0;
            else 
                ls[i][j]=space[i][j] * space[i][j];
        }
    }
    
    c[0]=0;
    
    for(int i=1;i<=n;i++)
    {
        c[i]=INT_MAX;
        for(int j=1;j<=i;j++)
        {
            if(c[j-1]!=INT_MAX && ls[j][i]!=INT_MAX && c[j-1]+ls[j][i]<c[i])
            {
                c[i]=c[j-1]+ls[j][i];
                p[i]=j;
            }
        }
    }
    printSolution(p,n);
    
}
int main()
{
    int T;
    
    cin>>T;
    
    while(T--)
    {
        int n;
        cin>>n;
        int a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int W;
        
        cin>>W;
        
       solveWordWrap(a,n,W);
       cout<<endl;
    }
    
    return 0;
}
