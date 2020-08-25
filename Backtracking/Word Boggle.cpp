//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/word-boggle/0

Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.

Example:

Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
       boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};

Output:  Following words of dictionary are present
         GEEKS, QUIZ

Input:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer x denoting the no of words in the dictionary. Then in the next line are x space separated strings denoting the contents of the dictinory. In the next line are two integers N and M denoting the size of the boggle. The last line of each test case contains NxM space separated values of the boggle.

Output:
For each test case in a new line print the space separated sorted distinct words of the dictionary which could be formed from the boggle. If no word can be formed print -1.

Constraints:
1<=T<=10
1<=x<=10
1<=n,m<=7

Example:
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ

*/


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
