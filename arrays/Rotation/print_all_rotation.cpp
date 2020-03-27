//Phoenix_RK


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            int m=(i+1)%n;
            cout<<a[i]<<" ";
            while(m!=i)
            {
                cout<<a[m]<<" ";
                m=(m+1)%n;
            }
            cout<<endl;
        }
        cout<<endl;
    }
	return 0;
}
