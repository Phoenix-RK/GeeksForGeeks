//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/combine-the-strings/0


Given N strings consisting of ‘R’ and ‘B’. Two strings can be only combined if last character of first string and first character of second string are same. Print the maximum length possible by combining strings.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting number of strings and the second line contains N space separated strings of equal length.

Output:
For each test case, in a new line print the maximum length possible. If no strings can combine then print "0".

Constraints:
1<=T<=100
2<=N<=1000
1<=|String length|<=1000

Example:
Input:
3
3
RBR BBR RRR
2
RRR BBB
7
RB RB RB RB RB RB RB

**********************************

Output:
9
0
0
*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
  	    cin>>n;
	
	    string s[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	      int rr_len= 0, bb_len = 0;
	      vector<int> rr,rb,br,bb;
          for(int i=0;i<n;i++)
            {
                int leng=s[i].size();
                if ( s[i][0] == 'R' && s[i][leng- 1] == 'R' )
                {
                    rr.push_back(leng);
                    rr_len+=leng; // combining multiple rr strings
                    //cout<<"rr "<<leng<<endl;
                }
                else if ( s[i][0] == 'R' && s[i][leng- 1] == 'B' )
                {
                    rb.push_back(leng); //storing the len of rb strings
                     //cout<<"rb "<<leng<<endl;
                }
                else if ( s[i][0] == 'B' && s[i][leng- 1] == 'B' )
                {
                    bb.push_back(leng);
                    bb_len+=leng; // combining multiple bb strings
                     //cout<<"bb "<<leng<<endl;
                }
                else if ( s[i][0] == 'B' && s[i][leng- 1] == 'R' )
                { 
                    br.push_back(leng); //storing the len of br strings	
                    // cout<<"br "<<leng<<endl;
                }
            }
            
            
            int ans=0;
            if(rb.size()==0 && br.size()==0)
            {
                ans=max(rr_len,bb_len); //if there are multiple rr or bb strings and no rb or br strings ...max len after combining can be given as output.
                if(rr.size()==1 && bb.size()==1) //if there is only one rr or bb, then there is no possible combining operation can be done...in that case we should output 0, not the max len of rr or bb
                    ans=0;
            }
           else
            {
                ans=rr_len+bb_len;
                sort(rb.begin(),rb.end(),greater<int>());
                sort(br.begin(),br.end(),greater<int>());
               /* for(int i=0;i<rb.size();i++)
                    cout<<rb[i]<<" ";
                cout<<endl;
                */
               /*
               for(int i=0;i<br.size();i++) 
                    cout<<br[i]<<" ";
                cout<<endl;
               */
                int no=min(rb.size(),br.size());
                for(int i=0;i<no;i++)
                {
//if one rb exist it can be combined with another br...to maximize the length formed by the rb br pair, sort the lens in desc order and take the possible no of pairs
                    ans+=rb[i]+br[i]; 
                }
                
//once the possible no of pairs are taken, at the end a string can be appended. That can be from either rb or br(which ever is left after we include in the previous step)
                if((rr_len!=0 || bb_len!=0 || rb.size()!=0) && (rb.size()<br.size()))
                    ans+=br[rb.size()];
                else if((rr_len!=0 || bb_len!=0 || br.size()!=0) && (br.size()<rb.size()))
                    ans+=rb[br.size()];
            }
           
                cout<<ans<<endl;
	    
	}
	return 0;
}
