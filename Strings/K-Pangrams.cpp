//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/k-pangrams/0

Given a String S and an integer k we need to find that whether the string can be changed into Pangram string by performing at most k changes and that changes can be only modification in a string (ie In one change we can remove existing character and add new character).




*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
    int T, k, count,extra;
	cin>>T;
	
	while(T--)
	{
	    int characters[26]={0};
	    
	    for(int i=0;i<26;i++)
	    {
	        characters[i]=0;
	    }
	    
	    count=0,extra=0;
	    
	    string s;
	    
	    cin>>s>>k;
    	
    
    	for(int i=0;s[i]!='\0';i++)
	    {
	        characters[s[i]-'a']++;
	    }
	   
    	for(int i=0;i<26;i++)
	    {
       //   cout<<characters[i]<<" ";
	        if(characters[i]==0)
	            count++;
	        else
	        {
	            extra=extra+characters[i]-1;
	        }
	           
	    }
	
	   // cout<<endl;
	   // cout<<"count= "<<count<<endl;
	   // cout<<"extra="<<extra<<endl;
	    if(k>=count && count<=extra)
	        cout<<"1"<<endl;
	    else
	        cout<<"0"<<endl;
	
	}
	return 0;
}
