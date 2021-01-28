//Phoenix_RK

/*



https://practice.geeksforgeeks.org/problems/match-specific-pattern/1/



Given a dictionary of words and a pattern. Every character in the pattern is uniquely mapped to a character in the dictionary. Find all such words in the dictionary that match the given pattern. 

Example 1:

Input:
N = 4
dict[] = {abb,abc,xyz,xyy}
pattern  = foo
Output: abb xyy
Explanation: xyy and abb have the same
character at index 1 and 2 like the
pattern.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMatchedWords() which takes an array of strings dict[] consisting of the words in the dictionary and a string, Pattern and returns an array of strings consisting of all the words in the dict[] that match the given Pattern in lexicographical order.

Expected Time Complexity: O(N*K) (where K is the length of the pattern).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10
*/



/* The function returns a  vector of strings 
present in the dictionary which matches
the string pattern.
You are required to complete this method */
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       //Your code here
       
      vector<string> res;
       int count=0;
       for(int i=0;i<dict.size();i++)
       {
           count=0;
           string s=dict[i];
           if(s.size()==pattern.size())
           {
               vector<int> v1(26);
               vector<int> v2(26);
               
               for(int j=0;j<s.size();j++)
               {
                   v1[s[j]-'a']++;
                   v2[pattern[j]-'a']++;
                   
                   if(v1[s[j]-'a']==v2[pattern[j]-'a'])
                   {
                       count++;
                   }
                   else
                     break;
               }
               if(count==s.size())
               {
                   res.push_back(s);
               }
           }
       }
       return res;
       
}



