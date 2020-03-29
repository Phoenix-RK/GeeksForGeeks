#include<bits/stdc++.h>
using namespace std;
int wildCard(string pattern,string str);
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           cout<<wildCard(pat,text)<<endl;
   }
}
// } Driver Code Ends
/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int m=pattern.length(),n=str.length();
    
        if (m == 0) 
        return (n == 0); 
  
      bool a[n+1][m+1];
    
      memset(a, false, sizeof(a)); 
  
      a[0][0]=true;

            /*for(int i=1;i<=n;i++)
        a[i][0]=false;*/
    for(int i=1;i<=m;i++)
        if(pattern[i-1]=='*')
            a[0][i]=a[0][i-1];
            
  
  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(pattern[j-1]=='*')
                a[i][j]=a[i][j-1]||a[i-1][j];
                
           
                
            else  if(pattern[j-1]=='?' || pattern[j-1]==str[i-1])
                a[i][j]=a[i-1][j-1];
            
            else
               a[i][j]= false;
        }
    }
    
    if(a[n][m]==true)
        return 1;
    else
       return 0;
    
}
