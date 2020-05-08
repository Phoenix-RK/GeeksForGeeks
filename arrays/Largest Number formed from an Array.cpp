//Phoenix-RK
/*


Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.The result is going to be very large, hence return the result in the form of a string.


Input:
2
5
3 30 34 5 9
4
54 546 548 60

Output:
9534330
6054854654
*/


//Phoenix_RK
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
 {
	//code
 int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n-1;j++)
	        {
	           string s1=to_string(a[j]);
	           //cout<<s1<<"s1\n";
	           string s2=to_string(a[j+1]);
	           //cout<<s2<<"s2\n";
	          // cout<<stoi(s2+s1)<<" "<<stoi(s1+s2)<<" \n";
	           if(stoi(s2+s1) > stoi(s1+s2))
	           {
	               int temp=a[j];
	               a[j]=a[j+1];
	               a[j+1]=temp;
	           }
	           
	           
	      }
	        
	        
	    }
	    
	    for(int i=0;i<n;i++)
	        cout<<a[i];
	    cout<<endl;
	
	}
	return 0;
}
