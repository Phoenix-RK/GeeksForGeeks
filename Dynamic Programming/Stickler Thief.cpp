//Phoenix_RK
/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] amount of money present in it.


Input:
2
6
5 5 10 100 10 5
3
1 2 3
Output:
110
4

Explanation:
Testcase1:
5+100+5=110
Testcase2:
1+3=4





*/
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
    
}

int main()
 {
	//code
    int T,n;
	cin>>T;
	while(T--)
	{
	    cin>>n;
	    int a[n],money[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   
	    if(n==0)
	    cout<<"0"<<endl;
	    else if(n==1)
	    cout<<a[0]<<endl;
	    else if(n==2)
	    cout<<max(a[0],a[1])<<endl;
	    else
	    {
	        money[0]=a[0];
	        money[1]=max(a[0],a[1]);
	        
	        for(int i=2;i<n;i++)
	        {
	            money[i]=max(money[i-2]+a[i],money[i-1]);
	        }
	        cout<<money[n-1]<<endl;
	    }
	    
	
	}
	return 0;
}
