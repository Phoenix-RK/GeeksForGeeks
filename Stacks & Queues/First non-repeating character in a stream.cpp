//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#

Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 

Example 1:

Input: A = "aabc"
Output: "a#bb"
Explanation: For every character first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - first non-repeating character is 'b'
Example 2:

Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
 

Your Task:
You don't need to read or print anything. Your task is to complete the function FirstNonRepeating() which takes A as input parameter and returns a string after processing the input stream.
 

Expected Time Complexity: O(26 * n)
Expected Space Complexity: O(26)
*/




class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string res="";
		    int freq[26];
		    memset(freq,0,sizeof(freq));
		    queue<char> q;
		    
		    for(int i=0;i<A.size();i++)
		    {
		        freq[A[i]-'a']++;
		        
		        q.push(A[i]);
		        
		        while(!q.empty())
		        {
		            if(freq[q.front()-'a']>1)
		                q.pop();
		          
		            else
		           {
		               res=res+q.front();
		               break;
		           }
		        }
		        if(q.empty())
		            res=res+"#";
		    }
		    
		    return res;
		}

};

