//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0

Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs more than once and whose index of second occurrence is smallest. S contains only lowercase letters.

*/


#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    int a[26]={0}, f=0,z;
	    char x;
	    cin>>s;
	    for(int i=0;i<s.size();i++)
	    {
	        a[s[i]-'a']++;
	        if(a[s[i]-'a']==2)
	        {
	            f=1;
	            x=s[i];
	            break;
	            
	        }
	    }
	    if(f==1)
	        cout<<x<<endl;
	    else 
	        cout<<-1<<endl;
	}
	return 0;
}
