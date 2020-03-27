//Phoenix_RK
/*
ROTATE AND DELETE
//////////////////////////////////////
Given an array arr[] of N integers. Do the following operation n-1 times. For every Kth operation:

Right rotate the array clockwise by 1.
Delete the (n-k+1)th last element.
Now, find the element which is left at last.
Testcase:
6
1 2 3 4 5 6
///////////////////////////////////
1 2  3 4 5 6        6 1 2 3 4 
4 6 1 2 3          4 6 1 3
3 4 6 1           3 6 1
1 3 6            3 6
6 3            3
*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int> a;
	    int x;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        a.push_back(x);
	    }
	    
	    int k=1;
	    while(a.size()>=1)
	    {
	        rotate(a.begin(),a.begin()+a.size()-1,a.end()); //clockwise rotation
	        int m=1+a.size()-k;
	        if(m>0)
	            a.erase(a.begin()+a.size()-k);
	        else
	            a.erase(a.begin());
	       k++;
	    }
	    
	    
	    cout<<a[0]<<endl;
	}
	
	
	return 0;
}
