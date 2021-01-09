//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1#


Given a binary matrix your task is to find all unique rows of the given matrix.

Example 1:

Input:
row = 3, col = 4 
M[][] = {{1 1 0 1},{1 0 0 1},{1 1 0 1}}
Output: 1 1 0 1 $1 0 0 1 $
Explanation: Above the matrix of size 3x4
looks like
1 1 0 1
1 0 0 1
1 1 0 1
The two unique rows are 1 1 0 1 and
1 0 0 1 .
Your Task:
You only need to implement the given function uniqueRow(). The function takes three arguments the first argument is a matrix M and the next two arguments are row and col denoting the rows and columns of the matrix. The function should return the list of the unique row of the martrix. Do not read input, instead use the arguments given in the function.

Note: The drivers code print the rows "$" separated.

Expected Time Complexity: O(row * col)
Expected Auxiliary Space: O(row * col)

Constraints:
1<=row,col<=40
0<=M[][]<=1

*/


struct Trie
{
  Trie* children[2];
  int count;
  bool isLeaf;
  Trie()
  {
      children[0]=NULL;
      children[1]=NULL;
      count=0;
      isLeaf=false;
  }
  
};


bool insert(struct Trie* root, int key[],int col) {
    // code here
    
    struct Trie* curr=root;
    curr->count+=1;
    for(int i=0;i<col;i++)
    {
        if(!curr->children[key[i]])
        {
            curr->children[key[i]]=new Trie();
        }
        curr=curr->children[key[i]];
        curr->count+=1;
    }
   
    curr->isLeaf=true;
  
    if(curr->isLeaf && curr->count==1)
        return true;

    return false;
}


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
    vector<vector<int>> res;
    Trie* root= new Trie();
    for(int i=0;i<row;i++)
    {
        if(insert(root,M[i],col))
        {
            vector<int> sub(col);
            for(int j=0;j<col;j++)
            {
                sub[j]=M[i][j];
            }
            res.push_back(sub);
        }
    }
    return res;
}

