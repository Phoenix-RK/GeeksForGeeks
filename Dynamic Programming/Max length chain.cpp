//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/max-length-chain/1

You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. Your task is to complete the function maxChainLen which returns an integer denoting the longest chain which can be formed from a given set of pairs. 

Input:
The first line of input contains an integer T denoting the no of test cases then T test cases follow .Then T test cases follow . The first line of input contains an integer N denoting the no of pairs . In the next line are 2*N space separated values denoting N pairs.

Output:
For each test case output will be the length of the longest chain formed.

Your Task:
Complete the function maxChainLen() which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

Expected Time Complexity: O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=100
1<=N<=100

Example(To be used only for expected output):
Input
2
5
5  24 39 60 15 28 27 40 50 90
2
5 10 1 11 
Output
3
1
Explanation
(i) the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
(ii) The max length chain possible is only of length one.



*********************************************************************************

Idea:

1)Sort the pairs such that they are arranged in increasing order of their first val
2)Now, solve as the Longest Increasing Subsequence problem, where p[i].first is compared against p[j].second and 0<=j<i ; update LIS 


*/

#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int max(int a,int b)
{
    return a>b?a:b;
}
void merge(struct val* p,int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    
    val L[n1],R[n2];
    
    for(int i=0;i<n1;i++)
    {
        L[i].first=p[l+i].first;
        L[i].second=p[l+i].second;
    }
    for(int j=0;j<n2;j++)
    {
        R[j].first = p[m+1+j].first;
        R[j].second = p[m+1+j].second;
    }
    
    
    i=0;
    j=0;
    k=l;
    
    while(i<n1 && j<n2)
    {
        if(L[i].first<=R[j].first)
        {
            p[k].first = L[i].first;
            p[k].second = L[i].second;
            i++;
        }
        
        else
        {
            p[k].first = R[j].first;
            p[k].second = R[j].second;
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
         p[k].first = L[i].first;
         p[k].second = L[i].second;
         i++;
         k++;
    }
    while(j<n2)
    {
        p[k].first = R[j].first;
        p[k].second = R[j].second;
        j++;
        k++;
        
    }
}
void sort(struct val* p,int l,int r)
{
    if(l<r)
    {
        int m = l +(r-l)/2;
        
        sort(p,l,m);
        sort(p,m+1,r);
        
        merge(p,l,m,r);
    }
}
int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p,0,n-1);

   /* for(int i=0;i<n;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;
    }
*/
    int LIS[n];
    int max_len=1;
    
    for(int i=0;i<n;i++)
        LIS[i]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[i].first > p[j].second && LIS[i]<=LIS[j])
                LIS[i]=1+LIS[j];
        }
        
        max_len=max(max_len,LIS[i]);
    }
    
    return max_len;

}

*/
