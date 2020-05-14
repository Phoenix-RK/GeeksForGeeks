//Phoenix_RK
/*


https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0

Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...


store the a[max_ind] as multiplier and a[i] as remainder

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
	    
	   
	    cin>>n;
	   long long int a[n],i;
	  
	    for( i=0;i<n;i++)
            cin>>a[i];
            
        long long int min_ind=0,max_ind=n-1,max_ele=a[n-1]+1;
        
        
        for(i=0;i<n;i++)
        {
            
            if(i%2==0)
            {
                a[i]=a[i]+(a[max_ind]%max_ele)*max_ele;
                max_ind--;
            }
            else
            {
                a[i]=a[i]+(a[min_ind]%max_ele)*max_ele;
                min_ind++;
            }
            
        }
        
	    for( i=0;i<n;i++)
	        cout<<a[i]/max_ele<<" ";
	    cout<<endl;
	
	}
	return 0;
}
