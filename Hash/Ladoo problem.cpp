//Phoenix_RK

/*

https://practice.geeksforgeeks.org/problems/ladoo-problem/0/


Bheem promised all his friends that if he won the tournament so he will give ladoos. But he knew that he can afford only one ladoo per day. If he is unable to give ladoo to any of his friend he will loose his friendship with them (if more than one his friend demanded for ladoo on same day). As he has won the tournament now he has to give ladoos to his friends. Now your task is to tell how many friends he will be able to save.

Input:
First line consists of T test case.
First line of every test case 'N', represents how many friends he has.
Second line of every test case Ai, represents which friend asked for ladoo on which day.

Output:
For each test case, Single line output denoting how many friends he is able to save.

Constraints:
1<=T<=100
1<=N<=1000
1<=Ai<=1000

Example:
Input:
1
5
3 3 1 2 4
Output:
4



*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        int count=0;
        set<int> s;
        for(int i=0;i<n;i++)
            s.insert(a[i]);
        
        
        cout<<s.size()<<endl;        
    }
    
}
