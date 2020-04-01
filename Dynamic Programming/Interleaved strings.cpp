//Phoenix_RK
/*
Given three strings A, B and C. Write a function that checks whether C is an interleaving of A and B. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.


*/
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends
/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    //Your code here
    int m=A.length(),n=B.length();
    
    if(m+n!=C.length())
        return false;
        
    bool val[n+1][m+1];
    memset(val,0,sizeof(val));
   
    for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 &&j==0)
                    val[i][j]=true;
                else if(i==0)
                {
                   
                            if(A[j-1]==C[j-1])
                                val[i][j]=val[i][j-1];
                            
                        
                }
                else if(j==0)
                {
                   
                            if(B[i-1]==C[i-1])
                                val[i][j]=val[i-1][j];
                            
                        
                }
    
             
        
               else if(A[j-1]==C[i+j-1] && B[i-1]!=C[i+j-1])
                    val[i][j]=val[i][j-1];
                
                else if(A[j-1]!=C[i+j-1] && B[i-1]==C[i+j-1])
                    val[i][j]=val[i-1][j];
                 
                else if(A[j-1]==C[i+j-1] && B[i-1]==C[i+j-1])
                    val[i][j]=(val[i-1][j]||val[i][j-1]);
                
                
            }
        }
    return val[n][m];
}

