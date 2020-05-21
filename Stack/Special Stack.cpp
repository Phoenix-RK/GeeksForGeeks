//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/special-stack/1

Design a data-structure SpecialStack (using the STL of stack) that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.

*/


#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}// } Driver Code Ends


/*Complete the function(s) below*/
stack<int> s2;
void push(int a)
{
     //add code here.
     
     s.push(a);
     if(s2.empty())
        s2.push(a);
     else if(s2.top()>=a)
        s2.push(a);
}

bool isFull(int n)
{
     //add code here.
     if(s.size()==n)
        return true;
        
    return false;
}

bool isEmpty()
{
    //add code here.
    if(s.size()==0)
    return true;
    
    return false;
}

int pop()
{
    //add code here.
    int x=s.top();
    s.pop();
    
    if(x==s2.top())
    s2.pop();
}

int getMin()
{
   //add code here.
   return s2.top();
}
