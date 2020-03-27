#include<bits/stdc++.h> 
using namespace std; 
bool search(int* a, int n,int target) 
{
        int p,l,h;
        for(int i=0;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                p=i;
                break;
            }
            
        }
        l=(p+1)%n;
        r=p;
        
        while(l!=r)
        {
            int sum=nums[l]+nums[r];
            if(sum==target)
                    return true;
            else if(sum<target)
                l=(l+1)%n;
            else
                r=(n+r-1)%n;
        }
   return false;
        
    }

int main() 
{ 
	int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int a[n],sum; 
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>sum;
	if (search(a, n, sum)) 
		cout << "True"; 
	else
		cout << "False"; 
	cout<<<endl;
}
	return 0; 
} 

