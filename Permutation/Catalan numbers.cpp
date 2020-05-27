//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/nth-catalan-number/0

https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/


*/
#include<bits/stdc++.h>
using namespace std;
#include <boost/multiprecision/cpp_int.hpp> 
using boost::multiprecision::cpp_int;
cpp_int binomial_coeff(cpp_int n,cpp_int k)
{
    cpp_int res=1;
    
    if(k>n-k)
        k=n-k;
        
    for(cpp_int i=0;i<k;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    
    return res;
}
cpp_int catalan(cpp_int n)
{
    cpp_int coeff=binomial_coeff(2*n,n);
    return coeff/(n+1);
}

int main()
 {
	//code
	cpp_int T,n;
	cin>>T;
	while(T--)
	{
	    
	    cin>>n;
	    cout<<catalan(n)<<endl;
	
	}
	return 0;
}
