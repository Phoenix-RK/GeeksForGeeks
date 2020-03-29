//Phoenix_RK
//You are given a tree and you need to do the level order traversal on this tree.
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */
//You are required to complete this method
void levelOrder(Node* node)
{
  //Your code here
  if(node==NULL)
  return;
  
  queue <Node *> q;
  q.push(node);
  
  while(!q.empty())
  {
     Node *root = q.front();
     q.pop();
     cout<<root->data<<" ";
      if(root->left!=NULL)
      {
          q.push(root->left);
      }
      if(root->right!=NULL)
          q.push(root->right);
  }
  
  
}

