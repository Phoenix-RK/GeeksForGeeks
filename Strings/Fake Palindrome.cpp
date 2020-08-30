//Phoenix_RK


/*
https://www.geeksforgeeks.org/walmart-interview-experience-aug-2020-on-campus/


Fake Palindrome: Return the number of Fake Palindrome substring in a string, where Fake Palindrome is a string whose anagram is a palindrome.
Test Case 1:  

Input: ABAB 
Output:7    
Explanation: (“A”,”B”,”A”,”B”,”ABA”,”BAB”,”ABAB”)
Test Case 2: 

Input: AAA 
Output: 6   
Explanation: (“A”,”A”,”A”,”AA”,”AA”,”AAA”) 
*/

#include<bits/stdc++.h>
using namespace std;
bool isFake(string a)
{
    map<char,int> m;
    for(int i=0;i<a.size();i++)
    {
        m[a[i]]++;
    }
    map<char,int>::iterator it;
    int count=0;
    for(it=m.begin();it!=m.end();it++)
    {
        if(((*it).second)%2==1)
        {
            count++;
            if(count>1)
                return false;
        }
    }
    return true;
    
}
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s1;
	    cin>>s1;
	    int count=0;
//for every substring check if it is fak palindrome
	    for(int i=0;i<s1.size();i++)
	    {
	        for(int l=1;l<=s1.size()-i;l++)
	        {
	           string s=s1.substr(i,l);
	           
	           if(isFake(s))
    	             count++;
	        }
	    }
	   cout<<count<<endl;
	}
	return 0;
}
