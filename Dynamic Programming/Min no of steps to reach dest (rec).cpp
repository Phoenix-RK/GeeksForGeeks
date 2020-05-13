//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    return a<b?a:b;
}
int rec(int src,int val,int dest)
{
    if(abs(src)>dest)
        return INT_MAX;
        
    if(src==dest)
        return val;
    
    int right=rec(src+val+1,val+1,dest);
    int left=rec(src-val-1,val+1,dest);
    
    return min(right,left);
    
}


int main()
 {

    int T,n;
	cin>>T;
	
	while(T--)
	{
	
    	int dest;
    	cin>>dest;
	    
	    cout<<rec(0,0,dest)<<endl;
	    
	    
	}
	return 0;
}
