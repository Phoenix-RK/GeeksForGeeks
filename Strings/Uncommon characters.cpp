//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/uncommon-characters/0

Find and print the uncommon characters of the two given strings S1 and S2. Here uncommon character means that either the character is present in one string or it is present in other string but not in both. The strings contains only lowercase characters and can contain duplicates.
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
	    string s1,s2;
	    cin>>s1>>s2;
	    
	    int freq1[26],freq2[26];
	    for(int i=0;i<26;i++)
	       {
	           freq1[i]=0;
	           freq2[i]=0;
	       }
	        
	    for(int i=0;i<s1.length();i++)
	   {
	       if(freq1[s1[i]-'a']==0)
	         freq1[s1[i]-'a']=freq1[s1[i]-'a']+1;
	   }
	   
	   for(int i=0;i<s2.length();i++)
	   {
	        if(freq2[s2[i]-'a']==0)
	         freq2[s2[i]-'a']=freq2[s2[i]-'a']+1;
	   }
	   
	   for(int i=0;i<26;i++)
	   {
	       if((freq1[i]!=0 && freq2[i]==0) || (freq1[i]==0 && freq2[i]!=0))
	        {
	            char c=i+97;
	            cout<<c;
	        }
	   }
	    
	   cout<<endl;
	}
	return 0;
}
