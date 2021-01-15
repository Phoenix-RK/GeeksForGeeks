//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/game-with-string4100/1#


Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.
 

Example 1:

Input: s = abccc, k = 1
Output: 6
Explaination:
We remove c to get the value as 12 + 12 + 22
 

Example 2:

Input: s = aabcbcbcabcc, k = 3
Output: 27
Explaination: We remove two 'c' and one 'b'. 
Now we get the value as 32 + 32 + 32.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minValue() which takes s and k as input parameters and returns the minimum possible required value.

 

Expected Time Complexity: O(N*logN)  where N is the length of string
Expected Auxiliary Space: O(N)

*/



//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        if(k>s.size())
            return 0;
        int val=0;
        int freq[26];
        memset(freq,0,sizeof(freq));
        priority_queue<int> pq;
        
        for(int i=0;s[i]!='\0';i++)
            freq[s[i]-'a']++;
            
        for(int i=0;i<26;i++)
        {
            pq.push(freq[i]);
        }
        
        while(k--)
        {
            int first=pq.top();
            pq.pop();
            first=first-1;
            pq.push(first);
        }
        
        while(!pq.empty())
        {
            int temp=pq.top();
            val+=(temp*temp);
            pq.pop();
        }
        return val;
    }
};
