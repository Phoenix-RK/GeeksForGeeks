//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0#





Given 3 strings X, Y and Z, the task is to find the longest common sub-sequence in all three given sequences.

 

Input:

The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains integers n, m and k denoting the length of strings X, Y and Z respectively.

The second line of each test case contains the three strings X, Y and Z. The string consists of only lower case english alphabets.

Output:

Print the length of the longest common sub- sequence of the three strings for each test case in a new line.


Constraints:
1<= T <=100
1<= N, M, K <=100


Example:
Input:
1
5 8 13
geeks geeksfor geeksforgeeks

Output:
5

Explanation:
All the 3 strings given have "geeks" as the longest subsequence present which has a length of 5.
geeks geeksfor geeksforgeeks




*/
#include<bits/stdc++.h>
using namespace std;

int lcs(int x, int y, int z, string s1, string s2,string s3){
    
    // your code here
    
	    int mem[x+1][y+1][z+1];
	
	    memset(mem,0,sizeof(mem));
	    
	    for(int i=1;i<=x;i++){
	        
	        for(int j=1;j<=y;j++)
	        {
	            for(int k=1;k<=z;k++)
	            {
	            
	            if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
	                mem[i][j][k]=mem[i-1][j-1][k-1]+1;
	            
	            else
	                mem[i][j][k]=max(mem[i-1][j][k],max(mem[i][j-1][k],mem[i][j][k-1]));
	        
	            }
	       }
	    }
	    
	    return mem[x][y][z];
}


int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        string s1,s2,s3;
        
        cin>>s1>>s2>>s3;
        
        
        cout<<lcs(x,y,z,s1,s2,s3)<<endl;
        
    }
    return 0;   
}

