//Phoenix_RK
/*


https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number/0


Given a number-line from -infinity to +infinity. You start at 0 and can go either to the left or to the right. The condition is that in ith move, you take i steps. You are given a Destination , you have to print the minimum number of steps required to reach that destination.

*/

#include<bits/stdc++.h>
using namespace std;

int steps(int dest)
{
    dest=abs(dest);
    int step=0,sum=0;
    while(sum<dest || (sum-dest)%2 !=0)
    {
        step++;
        sum=sum+step;
    }
    return step;
}

int main()
 {

    int T,n;
	cin>>T;
	
	while(T--)
	{
	
    	int dest;
    	cin>>dest;
	    
	    cout<<steps(dest)<<endl;
	    
	    
	}
	return 0;
}
