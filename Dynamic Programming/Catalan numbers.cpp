//Phoenix_RK
/*
https://practice.geeksforgeeks.org/problems/unique-bsts/0
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
