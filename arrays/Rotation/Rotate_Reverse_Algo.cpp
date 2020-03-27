//Phoenix_RK
/*
ROTATE-REVERSE ALGORITHM
Given an array of N size. The task is to rotate array by d elements where d is less than or equal to N.

Example:
Input
1
5
1 2 3 4 5
2

Output
3 4 5 1 2

*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t,n,m,x;
	cin>>t;
	while(t--)
	{
	    vector<int> a;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	         cin>>x;
	         a.push_back(x);
	    }
	    cin>>m;
        reverse(a.begin(),a.begin()+m);
        reverse(a.begin()+m,a.end());
        reverse(a.begin(),a.end());
        
        
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
            
        cout<<endl;
	}
	return 0;
}
