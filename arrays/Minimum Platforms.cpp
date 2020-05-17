//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/minimum-platforms/0

Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number of platforms required for the railway station so that no train waits.

*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int x;
	    vector<int> arr;
	    vector<int> dep;
	    for(int i=0;i<n;i++)
	   {
	       cin>>x;
	       arr.push_back(x);
	   }
	    for(int i=0;i<n;i++)
	   {
	       cin>>x;
	       dep.push_back(x);
	   }
	   
	   int i=1,j=0,max_platform=1,needed_platform=1;
	   sort(arr.begin(),arr.end());
	   sort(dep.begin(),dep.end());

	   while(i<n && j<n)
	   {
	       
	       if(arr[i]<=dep[j])
	       {
	           max_platform++;
	           i++;
	       }
	       else if(arr[i]>dep[j])
	       {
	           max_platform--;
	           j++;
	       }
	       
	       
	       needed_platform=max(max_platform,needed_platform);

	   }
	cout<<needed_platform<<endl;
	}
	return 0;
}
