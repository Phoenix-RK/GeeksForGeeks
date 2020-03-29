//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
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
	        
	    int curr_max=a[0],max_so_far=a[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        curr_max=max(a[i],curr_max+a[i]);
	        max_so_far=max(curr_max,max_so_far);
	    }
	    
	    cout<<max_so_far<<endl;
	}
	return 0;
}
