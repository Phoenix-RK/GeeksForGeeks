//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int catalan(int n)
{
    if(n==0 || n==1)
        return 1;
        
    int res=0;
    
    //summation of f(i-1)*f(n-i) for nodes from 1 to n 
    for(int i=0;i<n;i++)
    {
        res = res + catalan(i) * catalan(n-i-1);
    }
    
    return res;
}
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    
	    cout<<catalan(n)<<endl;
	
	}
	return 0;
}
