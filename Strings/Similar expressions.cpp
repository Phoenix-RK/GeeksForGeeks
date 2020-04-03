//Phoenix_RK
/*
Given two expressions in the form of strings. The task is to compare them and check if they are similar. Expressions consist of lowercase alphabets, '+', '-' and  '( )'.

Example:
Input:
2
-(a+b+c)
-a-b-c
a-b-(c-d)
a-b-c-d

Output:
YES
NO


*/
#include<bits/stdc++.h>
using namespace std;
void fill(string a,int v[])
{
    int temp_flag=0,i=0;
    bool flag=true;
    
    while(a[i]!='\0')
    {
        if(a[i]=='+')
            flag=(temp_flag%2==0);
        else if(a[i]=='-')
            flag=!(temp_flag%2==0);
        else if(a[i]=='(' && i>=1)
        {
            if(a[i-1]=='-')
                temp_flag++;
        }
        else if(a[i]==')')
        {
            if(temp_flag>0)
                temp_flag--;
        }
        else
        {
            if(flag)
                v[a[i]-'a']++;
            else
                v[a[i]-'a']--;
        }
        i++;
    }
    
    
}

bool valid(string b,int v[])
{
     int temp_flag=0,i=0;
    bool flag=true;
    
    while(b[i]!='\0')
    {
        if(b[i]=='+')
            flag=(temp_flag%2==0);
        else if(b[i]=='-')
            flag=!(temp_flag%2==0);
        else if(b[i]=='(' && i>=1)
        {
            if(b[i-1]=='-')
                temp_flag++;
        }
        else if(b[i]==')')
        {
            if(temp_flag>0)
                temp_flag--;
        }
        else
        {
            if(flag)
                v[b[i]-'a']--;
            else
                v[b[i]-'a']++;
        }
        i++;
    }
    
    for(int i=0;i<25;i++)
    {
        if(v[i]!=0)
            return false;
    }
    return true;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    string a,b;
	    cin>>a>>b;
	    int v[26];
	    memset(v,0,sizeof(v));
	    fill(a,v);
	    if(valid(b,v))
	        cout<<"YES"<<endl;
	    else
	        cout<<"NO"<<endl;
	}
	return 0;
}
