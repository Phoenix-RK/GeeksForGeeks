//Phoenix_RK
/*

https://practice.geeksforgeeks.org/problems/majority-element/0

Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

*/
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
int T,n;
	cin>>T;
	while(T--)
	{
	    int s,flag=0,x;
	    cin>>s;
	    vector<int> nums;
	    for(int i=0;i<s;i++)
	    {
	        cin>>x;
	        nums.push_back(x);
	        
	    }
        map<int,int> m;
        
        for(auto it=nums.begin();it!=nums.end();it++)
        {
            m[*it]++;
            if(m[*it]>s/2)
             {
                 flag=1;
                 cout<<*it<<endl;
                 
             }
        }
        if(!flag)
            cout<<"-1"<<endl;;
	
	}
	return 0;
}
