//Phoenix_RK


/*

https://www.interviewbit.com/problems/nearest-smaller-element/


Given an array of integers, find the nearest smaller number for every element such that the smaller element is on left side.
Examples:

Input:  arr[] = {1, 6, 4, 10, 2, 5}
Output:         {_, 1, 1,  4, 1, 2}
First element ('1') has no element on left side. For 6, 
there is only one smaller element on left side '1'. 
For 10, there are three smaller elements on left side (1,
6 and 4), nearest among the three elements is 4.

Input: arr[] = {1, 3, 0, 2, 5}
Output:        {_, 1, _, 0, 2}




*/


vector<int> Solution::prevSmaller(vector<int> &A) {

    vector<int> res;
    
    stack<int> s;

    for(int i=0;i<A.size();i++)
    {
        if(s.empty())
            res.push_back(-1);
            
        else if(s.size()>0 && A[i] > s.top())
            res.push_back(s.top());
        
        else if(s.size()>0 and A[i] < s.top())
        {
            while(s.size()>0 and A[i] <= s.top())
                s.pop();
            
            if(s.size()==0)
                res.push_back(-1);
            else
                res.push_back(s.top());
            
        }
        s.push(A[i]);
    }
  
    return res;
    
    
}
