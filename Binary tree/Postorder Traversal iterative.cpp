//Phoenix_RK


/*
https://practice.geeksforgeeks.org/problems/postorder-traversal/1


Given a binary tree, find the Postorder Traversal of it.
For Example, the postorder traversal of the following tree is:  5 10 39 1

        1
     /     \
   10     39
  /
5

Example 1:

Input:
        19
     /     \
    10      8
  /    \
 11    13
Output: 11 13 10 8 19

Example 2:

Input:
          11
         /
       15
      /
     7
Output: 7 15 11

*/




vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> res;
  if(root==NULL)
    return res;
    
  stack<Node*> s;
  while(!s.empty() || root!=NULL)
  {
      if(root)
      {
          s.push(root);
          root=root->left;
      }
      else
      {
          Node* temp=s.top()->right;
          if(temp==NULL)
          {
              temp=s.top();
              s.pop();
              res.push_back(temp->data);
              
              while(!s.empty() && temp==s.top()->right)
              {
                  temp=s.top();
                  s.pop();
                  res.push_back(temp->data);
              }
          }
          else
          {
              root=temp;
          }
      }
  }
  return res;
    
}
