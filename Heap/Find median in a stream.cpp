//Phoenix_RK


/*


https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#


Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
Your Task:
You are required to complete 3 methods insertHeap() which takes 1 argument, balanceHeaps() and getMedian() and returns the current median.
Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
 
Constraints:
1 <= N <= 106
1 <= x <= 106



*/


#include <bits/stdc++.h>
using namespace std;

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		void balanceHeaps(); //Method used by insertHeap
};


 // } Driver Code Ends

//max - max heap for lower values  (so that we can get highest value of lower range)
//min - min heap for higher values (so that we can get lowest value of higher range)

// Function to insert heap

void FindMedian::insertHeap(int &x)
{
	// Your code here
    if(max.size()==0)
    {
        max.push(x);
        return;
    }
    	
    if(max.size()>min.size())
    {
        if(max.top()>x)
        {
            min.push(max.top());
            max.pop();
            max.push(x);
        }
        else
        {
            min.push(x);
        }
    }
    //max - 1 2 3 //4
    //min - 5 6 7 8
    
    else
    {
        if(max.top()>x)
        {
            max.push(x);
        }
        else 
        {
            min.push(x);
            max.push(min.top());
            min.pop();
        }
    }
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
	// Your code here
	return ;
}

// Function to return getMedian
double FindMedian::getMedian()
{
	// Your code here
	
    if(max.size()>min.size())
        return max.top();
    else
        return (max.top()+min.top())/2.0;
}


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	FindMedian Ans;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		Ans.insertHeap(x);
    	    cout << floor(Ans.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends
