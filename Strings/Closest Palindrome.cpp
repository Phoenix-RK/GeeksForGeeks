//Phoenix_RK
/*

1)all nine
2)mirror image
3)dec and inc mid by one


*/
#include<bits/stdc++.h>
using namespace std;
#define CToI(x) (x - '0') 
#define IToC(x) (x + '0') 

bool isPalindrome(string n) 
{ 
	for (int i = 0; i < n.size() / 2; i++) 
		if (n[i] != n[n.size() - 1 - i]) 
			return false; 
	return true; 
} 

bool isallnine(string n)
{
    for(int i=0;i<n.size();i++)
    {
        if(n[i]!='9')
            return false;
    }
    return true;
}
string carryop(string num,int carry,int size)
{ 
	if (carry == -1) 
	{ 
		int i = size - 1; 
		while (i >= 0 && num[i] == '0') 
			num[i--] = '9'; 
		if (i >= 0) 
			num[i] = IToC(CToI(num[i]) - 1); 
     
	} 
	else
	{ 
		for (int i = size - 1; i >= 0; i--) 
		{ 
			int digit = CToI(num[i]); 
			num[i] = IToC((digit + carry) % 10); 
			carry = (digit + carry) / 10; 
		} 
	} 
	return num; 
} 
string mini(long long int num, long long int num1,long long int num2,long long int num3) 
{ 

	long long int Diff1 = abs(num - num1); 
	long long int Diff2 = abs(num - num2); 
	long long int Diff3 = abs(num3 - num); 

	if (Diff1 < Diff2 && Diff1 <= Diff3) 
		return to_string(num1); 
	else if (Diff3 < Diff2 && (Diff1 == 0 || Diff3 < Diff1)) 
		return to_string(num3); 
	else
		return to_string(num2); 
} 
string palindrome(string n)
{
    if(isPalindrome(n))
     return n;
    
   if (n.size() == 2 && stoi(n)==10) 
		return (to_string(stoi(n) +1)); 
    
    if(isallnine(n))
    {
        string s="1";
        for(int i=0;i<n.size()-1;i++)
            s=s+"0";
        s=s+"1";
        return s;
    }
        int l=n.size();
      
        string fh,mid,sh;
        fh=n.substr(0,l/2);
        sh=fh;
      
        reverse(sh.begin(),sh.end());
	if(l%2!=0)
	    mid=n[l/2];
	    
	string s1="",s2="",s3="",tfh="",tsh="";
	if(l%2==0)
	{
//2012  1999
//1991  1881
//2112  2002
	    int k = fh.size(); 
		    tfh = fh; 
	     	s1 = fh + sh; 
		if (fh[k - 1] == '0') 
			tfh = carryop(fh, -1, k); 
		else
			tfh[k - 1] = IToC(CToI(fh[k - 1]) - 1); 

		tsh = tfh; 
		reverse(tsh.begin(), tsh.end()); 
		s2 = tfh + tsh; 

		tfh = fh; 
		if (fh[k - 1] == '9') 
			tfh = carryop(fh, 1, k); 
		else
			tfh[k - 1] = IToC(CToI(tfh[k - 1]) + 1); 

		tsh = tfh; 
		reverse(tsh.begin(), tsh.end()); 
		 s3 = tfh+ tsh; 
	}

	else
	{   //12034   12934
            //11911   12834
            //12121   13031
	    s1=fh+mid+sh;
	    int m=fh.size();
	    if(mid=="0")
	    {
		tfh=carryop(fh,-1,m);
		tsh=tfh;
		reverse(tsh.begin(),tsh.end());
		s2=tfh+"9"+tsh;
	    }
	    else
		s2=fh+to_string(stoi(mid)-1)+sh;
		
	    if(mid=="9")
	    {
		tfh=carryop(fh,1,m);
		tsh=tfh;
		reverse(tsh.begin(),tsh.end());
		s3=tfh+"0"+tsh;
	    }
	    else
		s3=fh+to_string(stoi(mid)+1)+sh;
	}

    return mini(stoll(n),stoll(s1),stoll(s2),stoll(s3));
}

int main()
 {
	//code
	long long int T,n;
	cin>>T;
	while(T--)
	{
	
	    cin>>n;
	    cout<<palindrome(to_string(n))<<endl;
	
	}
	return 0;
}
