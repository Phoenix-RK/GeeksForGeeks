//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       10                       10 ------> NULL
      / \                       /      \
     3   5       =>     3 ------> 5 --------> NULL
    / \     \               /  \           \
   4   1   2          4 --> 1 -----> 2 -------> NULL

 


*/




void connect(Node* p)
{
    if(p==NULL)
        return;
        
    queue<Node*> q;
    q.push(p);
    
    while(!q.empty())
    {
        int s=q.size();
        Node* prev=NULL;
        while(s--)
        {
            Node* temp=q.front();
             q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
                
            if(prev!=NULL)
                prev->nextRight=temp;
                
         prev=temp;
        }
        prev->nextRight=NULL;
        
    }
    
}
