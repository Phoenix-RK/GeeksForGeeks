//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/unique-bsts/0


Catalan numbers:
https://www.youtube.com/watch?v=CMaZ69P1bAc

https://www.coursera.org/lecture/enumerative-combinatorics/generating-function-for-catalan-numbers-XY7rw
 

https://www.youtube.com/watch?v=m9Khxn2g-6w

https://www.youtube.com/watch?v=QdcujZTp_8M
*/

#include<bits/stdc++.h>
using namespace std;

int main()
 {
	//code
	 int T,n,a[12];
    a[0]=a[1]=1;
    
    for(int i=2;i<12;i++)
    {
        a[i]=0;
        for(int j=0;j<i;j++)
        {
            a[i]=a[i]+ a[j]*a[i-j-1];
        }
    }
	
    cin>>T;
    while(T--)
	{
		cin>>n;

		cout<<a[n]<<endl;

	}
	return 0;
}


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
cpp_int findCatalan(int n)
{
    cpp_int coeff=binomial_coeff(2*n,n);
    return coeff/(n+1);
}
