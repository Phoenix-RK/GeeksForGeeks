//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
https://www.youtube.com/watch?v=nYFd7VHKyWQ

Given a string S. The task is to print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA

Explanation:
Testcase 1: Given string ABC has permutations in 6 forms as ABC, ACB, BAC, BCA, CAB and CBA .





*/
#include<bits/stdc++.h>
using namespace std;
void permutation(char* key,int* count, int index, int level, vector<vector<string>> &output,vector<string> sub_res)
{
    if(level == sub_res.size())
    {
        output.push_back(sub_res);
        return;
    }
    
    for(int i=0;i<index;i++)
    {
        if(count[i]==0)
            continue;
            
        sub_res[level]=key[i];
        count[i]--;
        permutation(key,count,index,level+1,output,sub_res);
        count[i]++;
    }
    
}
vector<vector<string>> permute(string s)
{
    map<char,int> m;
    vector<vector<string>> output;
    vector<string> sub_res(s.size());
    for(int i=0;i<s.size();i++)
    {
        if(m.find(s[i])==m.end())
            m[s[i]]=1;
        else
            m[s[i]]++;
    }
    
    char* key =new char[m.size()];
    int* count =new int[m.size()];
    int index=0;
    for(auto it=m.begin();it!=m.end();it++)
    {
        key[index]=it->first;
        count[index]=it->second;
        index++;
        
    }
    int level=0;
    permutation(key,count,index,level,output,sub_res);
    return output;
    
}

int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    string s;
	    cin>>s;
	    vector<vector<string>> output;
	    output = permute(s);
	   for(int i=0;i<output.size();i++)
	   {
	       for(int j=0;j<output[i].size();j++)
	            cout<<output[i][j];
	       cout<<" ";
	   }

	    
	   cout<<endl;
	    
	}
	return 0;
}
