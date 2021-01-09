//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/rearrange-characters/0#

Given a string S with repeated characters (only lowercase). The task is to rearrange characters in a string such that no two adjacent characters are same.

Note : It may be assumed that the string has only lowercase English alphabets.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a single line containing a string of lowercase english alphabets.

Output:
For each test case in a new line print "1" (without quotes) if the generated string doesn't contains any same adjacent characters, else if no such string is possible to be made print "0" (without quotes).

Constraints:
1 <= T <= 100
1 <= length of string <= 104

Example:
Input:
3
geeksforgeeks
bbbabaaacd
bbbbb

Output:
1
1
0

Explanation:
Testcase 1: All the repeated characters of the given string can be rearranged so that no adjacent characters in the string is equal.
Testcase 3: Repeated characters in the string cannot be rearranged such that there should not be any adjacent repeated character.
*/


#include<bits/stdc++.h>
using namespace std;
typedef pair<char,int> pd;
class compare
{
public:
    bool operator() (pair<char,int>  a, pair<char,int> b)
    {
        return a.second<b.second;
    }
};


bool reorganizeString(string S) {
        map<char,int> m;
        //string res="";
        
        for(auto i : S)
            m[i]++;
        
        priority_queue<pd,vector<pd>,compare> pq; 
        
        for(auto i : m)
        {
            pq.push({i.first,i.second});
        }
        
        while(pq.size()>1)
        {
            pd curr = pq.top();
            pq.pop();
            pd next = pq.top();
            pq.pop();
            //res=res+curr.first+next.first; 
            
        
            m[curr.first]=curr.second-1;
            m[next.first]=next.second-1;
              
            if(m[curr.first]>0)
                pq.push({curr.first,m[curr.first]});
            if(m[next.first]>0)
                pq.push({next.first,m[next.first]});
            
        }
        if(!pq.empty())
        {
            pd curr = pq.top();
            pq.pop();
            if(curr.second>1)
                return false;
            //res=res+curr.first;
        }
        return true;
}

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        string s;
        cin>>s;
        
        cout<<reorganizeString(s)<<endl;
    }
}
