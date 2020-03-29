//Phoneix_RK


void levelOrder(Node* node)
{
  
  queue<struct Node*> q;
  q.push(node);

  while(!q.empty())
  {
      int s=q.size();
      while(s>0){
         
      struct Node* temp=q.front();
      
      cout<<temp->data<<" ";
      if(temp->left)
        q.push(temp->left);
      if(temp->right)
        q.push(temp->right);
        
        q.pop();
        
        s--;
      }
      
      cout<<endl;
    
  }
  
  
}
