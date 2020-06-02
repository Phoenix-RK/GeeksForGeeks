//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/non-repeating-character/0


Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,flag=0;
    	cin>>n;
	    string s;
	    cin>>s;

	    int a[26]={0};
	    
	    for(int i=0;i<n;i++)
	    {
	        a[s[i]-'a']=a[s[i]-'a']+1;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(a[s[i]-'a']==1)
	        {
	            cout<<s[i];
	            flag=1;
	            break;
	        }
	    }
	    if(!flag)
	        cout<<"-1";
	    cout<<endl;
	    
	}
	return 0;
}
