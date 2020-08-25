//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1

Given a string S containing only digits, Your task is to complete the function genIp() which returns a vector containing all possible combination of valid IPv4 ip address and takes only a string S as its only argument.
Note : Order doesn't matter.

For string 11211 the ip address possible are 
1.1.2.11
1.1.21.1
1.12.1.1
11.2.1.1

Example 1:

Input:
S = 1111
Output: 1.1.1.1

Your Task:

Your task is to complete the function genIp() which returns a vector containing all possible combination of valid IPv4 ip address in sorted order and takes only a string S as its only argument.

Expected Time Complexity: O(N * N * N * N)
Expected Auxiliary Space: O(N * N * N * N)


*/
#include <bits/stdc++.h>

using namespace std;

vector<string> genIp(string &s);

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        vector<string> str = genIp(s);
        sort(str.begin(), str.end());
        for (auto &u : str) {
            cout << u << "\n";
        }
    }
}// } Driver Code Ends


/*You are required to complete this method*/

void solve(string s,int index,vector<string>& ans,int dotnum)
{
    if(dotnum<=3 && index>=s.size())
        return;
        
    if(dotnum==4 && index<s.size())
    {
        string p=s;
        p.push_back('.');
        int st=0;
        for(int i=0;i<p.length();i++)
        {
            if(p[i]=='.')
            {
                string val=p.substr(st,i-st);
                st=i+1;
                
                if(val[0]=='0'&& val.size()>1)
                    return;
                    
                long long num=stoll(val);
                
                if(num>255)
                    return;
            }
        }
        ans.push_back(s);
        return;
    }
    
    
    for(int i=index;i<s.size()-1;++i)
    {
        string temp1=s.substr(0,i+1);
        string temp2=s.substr(i+1);
        
        temp1=temp1+".";
        temp1=temp1+temp2;
        
        solve(temp1,i+2,ans,dotnum+1);
    }
    return;
}


vector<string> genIp(string &s) {
    // Your code here
    
    vector<string> ans;
  
    if(s.size()>3)
        solve(s,0,ans,1);
    return ans;
}

