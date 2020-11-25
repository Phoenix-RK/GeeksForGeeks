//Phoenix_RK

/*


https://practice.geeksforgeeks.org/problems/power-set4302/1#


Given a string S find all possible substrings of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc câ€‹
Explanation : There are 7 substrings that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.
Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
 

Constraints: 
1 <= Length of string <= 16

			    
	a b c
	j

	x=3;
	size=8;

	i=0 j=0              i=2 j=0             i=4 j=0                i=6 j=0
	0000 &               0010                0100                   0110
	0001                 0001                0001                   0001  

	i=0 j=1              i=2 j=1             i=4 j=1                i=6 j=1                 
	0000                 0010                0100                   0110
	0010                 0010  sub=b**       0010                   0010   sub=b

	i=0 j=2              i=2 j=2             i=4 j=2                i=6 j=2
	0000                 0010                0100                   0110
	0100                 0100                0100   sub=c*          0100  sub=bc**
	-------------------  ------------------ -----------------
	i=1 j=0              i=3 j=0             i=5 j=0                i=7 j=0            
	0001                 0011                0101                   0111                
	0001                 0001                0001   sub=a           0001 sub=a 
	-----               ------
	0001     sub=a**     0001  sub=a

	i=1 j=1              i=3 j=1             i=5 j=1                i=7 j=1
	0001                 0011                0101                   0111
	0010                 0010                0010                   0010 sub=ab
	-----                -----
	0000                 0010   sub=ab**

	i=1 j=2              i=3 j=2             i=5 j=2                i=7 j=2
	0001                 0011                0101                   0111
	0100                 0100                0100                   0100 sub=abc**
	----                                    ------
	0000                                     0100  sub=ac**
------------------------------------------------------------------
   
		  */

class Solution{
	public:
		vector<string> AllPossibleStrings(string s)
		{
		   
		        
		    
		    vector<string> res;
		    
		    int x=s.length();
		    
		    int size= pow(2,x);
		    for(int i=0;i<size;i++)
		    {
		        string sub;
		        for(int j=0;j<x;j++)
		        {
		            if(i & (1<<j))
		            {
		                //cout<<"i="<<i<<" j="<<j<<endl;
		                sub=sub+s[j];
		                //cout<<"sub-p="<<sub<<endl;
		            }
		        }
		        if(sub.size()!=0)
		        {
    		        //cout<<"sub="<<sub<<endl;
    		        res.push_back(sub);
		        }
		    }
		     sort(res.begin(),res.end());
		     return res;
		    
		}
};
