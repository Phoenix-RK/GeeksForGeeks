//Phoenix_RK

/*
https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1


You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer Q denoting the number of queries.
A Query Q may be of 3 Types:
    1. 1 x (a query of this type means  pushing 'x' into the stack)
    2. 2 (a query of this type means to pop element from stack and print the poped element)
    3. 3 (a query of this type means to print the minimum element from the stack)
The second line of each test case contains Q queries seperated by space.

Output:
The output for each test case will  be space separated integers having -1 if the stack is empty else the element poped out  or min element from the stack.



*/
//works for both positive and negative numbers
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
    if(s.empty())
       return -1;

     return minEle;  
    
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   
   if(s.empty())
        return -1;
        
    int y=s.top();
    s.pop();
 
 
  if(y<minEle)
  {
       int temp = minEle;
       minEle = 2*minEle - y;
       return temp;
   }
   else
    return y;

}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty())
   {
        minEle=x;
        s.push(x);
        return;
   }
    if(x<minEle)
    {
       s.push(2*x-minEle);
       minEle=x;
       
    }
    else
       s.push(x);
    
   
}
/*********************************************************************/
//works only for positive numbers
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
    if(s.empty())
       return -1;

     return minEle;  
    
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   
   if(s.empty())
        return -1;
   int y=s.top();
   s.pop();
 
   if(y>=0)
   {
       return y;
   }

   else
   {
       int temp = minEle;
       minEle = minEle - y;
       return temp;
      
   }
   

}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty())
   {
        minEle=x;
        s.push(x);
        return;
   }
    if(x<minEle)
    {
     
       s.push(x-minEle);
       minEle=x;
       
    }
    else
       s.push(x);
    
   
}

