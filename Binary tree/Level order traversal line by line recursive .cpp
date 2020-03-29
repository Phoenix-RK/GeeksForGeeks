//Phoneix_RK
//You are required to complete this method
int findheight(Node *node)
{
    if(node==NULL)
        return 0;
    int lheight=findheight(node->left);
    int rheight=findheight(node->right);
    
    if(lheight>rheight)
     return lheight+1;
    else 
     return rheight+1;
}

void printLevel(Node *node,int level)
{
    if(node==NULL)
        return;
    if(level==0)
        cout<<node->data<<" ";
    else
      {
          printLevel(node->left,level-1);
          printLevel(node->right,level-1);
          
      }
}
void levelOrder(Node* node)
{
  //Your code here
  
 int height=findheight(node);
 for(int i=0;i<height;i++)
  {  printLevel(node,i);
  cout<<endl;
  }
}
