//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap/0#



Given two binary max heaps as arrays, merge the given heaps, after merging the two arrays.
The task is very simple to merge the two arrays firstly keep all the elements of first array than elements second array, than apply the merge operation of heaps.

Input:
First line consists of T test cases. First line of every test case consists of 2 integers N and M, denoting the number elements of two arrays (MAX HEAP). Second and third line of every test cases consists of elements of 2 Heaps respectively.

Output:
Single line output, print the merged max heap.

Constraints:
1<=T<=100
1<=N,M<=100

Example:
Input:
1
4 3
10 5 6 2
12 7 9
Output:
12 10 9 2 5 7 6 



*/

//Phoenix_RK
#include<bits/stdc++.h>
using namespace std;

void heapify(int* c, int n,int i)
{
    int largest=i;
    int l=2*i + 1;
    int r=2*i + 2;
    
    if(l<n && c[l]>c[largest])
        largest=l;
    if(r<n && c[r]>c[largest])
        largest=r;
    
    if(largest!=i)
    {
        swap(c[i],c[largest]);
        heapify(c,n,largest);
    }
}

void heap(int a[],int b[],int n,int m,int c[])
{
    int k=0;
    for(int i=0;i<n;i++)
        c[k++]=a[i];
        
    for(int i=0;i<m;i++)
        c[k++]=b[i];
        
    for(int i=(k-1)/2;i>=0;i--)
    {
        heapify(c,k,i);
    }
}

int main()
{
    int T;
    cin>>T;
    
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        int c[n+m];
        
        heap(a,b,n,m,c);
        
        for(int i=0;i<m+n;i++)
            cout<<c[i]<<" ";
            
        cout<<endl;
    }
}
