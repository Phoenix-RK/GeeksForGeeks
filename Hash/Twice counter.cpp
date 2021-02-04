//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/twice-counter4236/1/


Given a list of N words. Count the number of words that appear exactly twice in the list.

Example 1:

Input:
N = 3
list = {Geeks, For, Geeks}
Output: 1
Explanation: 'Geeks' is the only word that 
appears twice. 
Example 2:

Input:
N = 8
list = {Tom, Jerry, Thomas, Tom, Jerry, 
Courage, Tom, Courage}
Output: 2
Explanation: 'Jerry' and 'Courage' are the 
only words that appears twice. 

Your Task:  
You dont need to read input or print anything. Complete the function countWords() which takes integer N and list of strings as input parameters and returns the number of words that appear twice in the list.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N) 


*/



class Solution
{
    public:
        int countWords(string list[], int n)
        {
           //code here.
           int count=0;
           map<string,int> m;
           for(int i=0;i<n;i++)
           {
               m[list[i]]++;
               if(m[list[i]]==2)
                count++;
            
                if(m[list[i]]==3)
                count--;
           }
           
           return count;
        }

};

