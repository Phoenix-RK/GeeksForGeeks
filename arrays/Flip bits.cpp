//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int find_sum(vector<int>a,int n)
{
    int curr_max=0,max_so_far=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        curr_max=max(a[i],curr_max+a[i]);
	        max_so_far=max(curr_max,max_so_far);
	    }
	    
	    return max_so_far;
}
int main()
 {
	//code
   int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    vector<int> a(n);
	    int max=0,c=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	       
	    }
	    int one = count(a.begin(),a.end(),1);
	    replace(a.begin(),a.end(),1,-1);
	    replace(a.begin(),a.end(),0,1);
	    
	    int sum=find_sum(a,n);
	    cout<<sum+one<<endl;
	}
	return 0;
}
