//Phoenix_RK




/*


Write a program to reverse a stack using recursion. You are not allowed to use loop constructs like while, for..etc, and you can only use the following ADT functions on Stack S: 
isEmpty(S) 
push(S) 
pop(S)


The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, insert all held items one by one at the bottom of the stack. 
For example, let the input stack be  

    1  <-- top
    2
    3
    4    
First 4 is inserted at the bottom.
    4 <-- top

Then 3 is inserted at the bottom
    4 <-- top    
    3

Then 2 is inserted at the bottom
    4 <-- top    
    3 
    2
     
Then 1 is inserted at the bottom
    4 <-- top    
    3 
    2
    1
*/

void insert(stack<int> s,int i)
{
	if(s.empty())
	{
		s.push(i);
		return;
	}
	int curr=s.top();
	s.pop();
	insert(s,i);
	s.push(curr);

} 
void reverse(stack<int> s)
{
	if(!s.empty())
	{
		int t = s.top();
		s.pop();	
		reverse(s);

		insert(s,t);

	}

}


