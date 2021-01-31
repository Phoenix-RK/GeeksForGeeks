//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/


Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Example 1:

Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac
Explanation: There are 2 groups of
anagrams god, dog make group 1.
act, cat, tac make group 2. 
Your Task:
The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)


*/


vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    
    vector<vector<string>> res;
    
    map<string,vector<string>> m;
    
    for(int i=0;i<string_list.size();i++)
    {
        string temp=string_list[i];
        sort(temp.begin(),temp.end());
        m[temp].push_back(string_list[i]);
    }

    map<string,vector<string>> :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
       
        res.push_back(it->second);
        
    }
    return res;
    
}


