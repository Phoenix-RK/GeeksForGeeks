//Phoenix_RK


/*

Design a stack with operations on middle element







*/


void deleteMid(stack<char> a,int n,int curr=0)
{

	if(!a.empty() && curr==n)
	 return;

	int x = a.top();
	a.pop(); 
	
	deleteMid(a,n,curr+1);
	
	if(curr!=floor(n/2)+1)
		a.push(x);
}
