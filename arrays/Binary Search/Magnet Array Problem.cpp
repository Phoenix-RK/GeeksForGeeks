//Phoenix_RK

/*


Magnets are placed on X axis, the coordinates of which are given, you are asked to find out the X-co-ordinates of all the equilibrium points (i.e. the point where net force is zero).
You notice that point each magnet repels each other, it means the polarity of the magnet is such that exerts +ve force in its right side and -ve force in left side, (here +ve is considered in +ve direction of x-axis).



*/
#include<bits/stdc++.h>
using namespace std;
double calc(double mid,double a[],int n)
{
    double x=0;
    for(int i=0;i<n;i++)
    {
        x+=1/(mid-a[i]);
    }
    return x;
}

double search(double l,double r,double a[],int n)
{
    while(l<r)
    {
        double mid=r+(l-r)*0.50;
        double val=calc(mid,a,n);
        if(abs(val)<=0.0000000000001) //first we check equi pt is at mid 
          return mid;
       //if not   
        if(val>0) //case 1: force>0 (ie.) force exerted  by the charges in lhs is stronger than rhs...so move away from lhs  
                l=mid; 

        else ////case 2: force<0 (ie.) force exerted  by the charges in rhs is stronger than lhs...so move away from rhs 
            r=mid;
    }
    return l;
}

int main()
 {
	//code
	 int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    double a[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    for(int i=1;i<n;i++)
	        printf("%0.2f ",search(a[i-1],a[i],a,n));
	cout<<endl;
	}
	return 0;
}
