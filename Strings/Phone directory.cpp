//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/phone-directory/0#

Given a list of contacts which exist in a phone directory and a query string str. The task is to implement search query for the phone directory. Run a search query for each prefix p of the query string str(i.e from  index 1 to str length) that prints all the distinct recommended contacts which have the same prefix as our query (p) in lexicographical order. Please refer the explanation part for better understanding.

NOTE: If there is no match between query and contacts , print "0".

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains three lines. First line of each test case contains N i.e., number of contacts. Second line contains space separated all the contacts in the form of string. And third line contains query string.

Output
For each test case, print each query result in new line. If there is no match between query and contacts, print "0".

Constraints:
1<=T<=100
1<=N<=50
1<=|contact[i].length|<=50
1<=|query length|<=6

Example:
Input:
1
3
geeikistest geeksforgeeks geeksfortest
geeips

Output:

geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest geeksforgeeks geeksfortest
geeikistest
0
0
Explanation:

By running the query on contact list, we get, 
Suggestions based on "g" are: 
geeikistest geeksforgeeks geeksfortest 
Suggestions based on "ge" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "gee" are:
geeikistest geeksforgeeks geeksfortest
Suggestions based on "geei" are:
geeikistest
No Results Found for "geeip", So print "0".
No Results Found for "geeips", So print "0".    

*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int t;
    cin>>t;
    while(t--)
    {
        set<string>s;
        string test;
        int n;
        cin>>n;
        string a;
        for(int i = 0; i < n; i++)
        {
            cin>>a;
            s.insert(a);
        }
        
        cin>>test;
        vector<string>v;
        for(auto i : s)
        {
            v.push_back(i);
        }
        
        for(int i =0; i < test.size(); i++)
        {
            vector<string>ans;
            for(int j = 0; j < v.size(); j++)
            {
                if(v[j][i] == test[i])
                    ans.push_back(v[j]);
            }
            if(ans.size() == 0)
                cout<<0<<" ";
            else
            {
                for(auto i : ans)
                    cout<<i<<" ";
            }
            cout<<endl;
            v = ans;
            ans.clear();
        }
    }
    return 0;
}


