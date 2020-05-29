//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/word-boggle/0

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

*/

#include<bits/stdc++.h>
using namespace std;
bool visited[8][8]={{false}};
void reset()
{
     
	    for(int i=0;i<8;i++)
	    {
	        for(int j=0;j<8;j++)
	        {
	            visited[i][j]=false;
	        }
	    }
}

bool search(int j,int k,int m,int n,string s,int leng,int ind,vector<char> a[])
{
    if(ind==leng)
        return true;
        
    if(j<0 || k<0 || j>m || k>n || s[ind]!=a[j][k] || visited[j][k]==true )
        return false;
        
    if(s[ind]==a[j][k])
    {
        visited[j][k]=true;
        
        if(search(j-1,k-1,m,n,s,leng,ind+1,a) || search(j-1,k,m,n,s,leng,ind+1,a) || search(j-1,k+1,m,n,s,leng,ind+1,a) || search(j,k-1,m,n,s,leng,ind+1,a) || search(j,k+1,m,n,s,leng,ind+1,a) || search(j+1,k-1,m,n,s,leng,ind+1,a) || search(j+1,k,m,n,s,leng,ind+1,a) || search(j+1,k+1,m,n,s,leng,ind+1,a) )
        {
            return true;
        }
        
        
    }
    visited[j][k]=false;
    return false;
}

int main()
 {
	//code
    int T,n;
	cin>>T;
	while(T--)
	{
	    int no;
	    cin>>no;
	    vector<string> x;
	    string s;
	    for(int i=0;i<no;i++)
       {
           cin>>s;
           x.push_back(s);
       }
	        
	    int m,n;
	    cin>>m>>n;
	   
	     vector<char>a[m];
         for (int i=0;i<m;i++)
         {
            for(int j=0;j<n;j++)
            {
                char f;
                cin>>f;
                a[i].push_back(f);
            }
         }
	    
	    
	    set<string> words;
	    
	    for(int i=0;i<no;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            for(int k=0;k<n;k++)
	            { 
	                if(x[i][0]==a[j][k] && search(j,k,m,n,x[i],x[i].length(),0,a))
	                {
	                    words.insert(x[i]);
	                    reset();
	                   
	                }
	            }
	        }
	    }
	    
	    if(words.size()>0)
	    {
	        for(auto it=words.begin();it!=words.end();it++)
	            cout<<*it<<" ";
	    }
	    else
	    cout<<"-1";
	
	    cout<<endl;
	}
	return 0;
}
