//Phoenix_RK

/*



A step array is an array of integer where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple element exist return the first occurrence of the key.

Examples:

Input : arr[] = {4, 5, 6, 7, 6}
           k = 1
           x = 6
Output : 2
The first index of 6 is 2.

Input : arr[] = {20, 40, 50, 70, 70, 60}  
          k = 20
          x = 60
Output : 5
The index of 60 is 5

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{

	int T;
	cin>>T;

	while(T--)
	{
		int n,k,target;
		cin>>n;
		int a[n];
		

		for(int i=0;i<n;i++)
			cin>>a[i];

		cin>>k>>target;
		
		int flag=1, low=0;	
		while(low<n)
		{
			if(a[low]==n)
			{
				flag=0;
				cout<<low<<endl;
				break;
			}
			low=low+(abs(a[low]-target)/k);
		}

		if(flag)
			cout<<"-1"<<endl;
	}

	return 0;
}
