//Phoenix-RK
/*
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

void create(Node *root,int hd,int d,map<int,pair<int,int>> &m)
{
    if(root==NULL)
        return ;
    if(m.find(hd)==m.end())
    {
        m[hd]=make_pair(d,root->data);
    }
    else
    {
        pair<int,int> p=m[hd];
        if(p.first>d) //no = ...because even with the nodes on same level the one that occur on the left must appear in the top view
        {
            m[hd].first=d;
            m[hd].second=root->data;
        }
    }
    
    create(root->left,hd-1,d+1,m);
    create(root->right,hd+1,d+1,m);
}

void topView(struct Node *root)
{
    //Your code here
    int hd=0,d=0;
    map<int,pair<int,int>> m;
    create(root,hd,d,m);
    
      map<int,pair<int,int>> :: iterator it;
      
      for(it=m.begin();it!=m.end();it++)
      {
          cout<<it->second.second<<" ";
      }
    
    
    
}



