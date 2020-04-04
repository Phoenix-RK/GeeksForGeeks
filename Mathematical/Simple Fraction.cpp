//Phoenix_RK
//infact it is a very simple fraction 
#include<bits/stdc++.h>
using namespace std;
void fn(int num,int den)
{
    map<int,int> m;
    string s="";
    cout<<num/den;
    int rem=num%den;
    while(rem!=0 && m.find(rem)==m.end())
    {
        m[rem]=s.length();
        int n=rem*10;
        s=s+to_string(n/den);
        rem=n%den;
    }
    if(s.length()==0)// 10/2 -->only integral part
    return;
    if(rem==0)
        {
            cout<<"."<<s; //for 5/4 -->non repeatitive
            return ;
        }
    else
    {
     
        cout<<"."<<s.substr(0,m[rem])<<'('<<s.substr(m[rem])<<')'; //repeatetive
       
    }
    return;
}
int main()
 {
	//code
	 int T;
	cin>>T;
	while(T--)
	{
	    int m,n;
	    cin>>m>>n;
        fn(m,n);
        cout<<endl;
	
	}
	return 0;
}
