//Phoenix_RK



/*

https://www.interviewbit.com/problems/shortest-unique-prefix/


Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}
where we can see that
zebra = z
dog = dog
duck = du
dove = dov
*/

struct Trie{
    
    Trie* children[26];
    int count=0;
    
    Trie()
    {
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

void insertTrie(Trie* root,string s)
{
    Trie* curr=root;
   
    
    for(int i=0;s[i]!='\0';i++)
    {
        int ind=s[i]-'a';
        
        if(!curr->children[ind])
            curr->children[ind]=new Trie();
        
        curr->count+=1;
        curr=curr->children[ind];
    }
}

string getPrefix(Trie* root,string s)
{
    string res="";
    Trie* curr= root;

    for(int i=0;s[i]!='\0';i++)
    {
        
        int ind=s[i]-'a';
        if(curr->count==1)
            return res;
        res=res+s[i];
        curr=curr->children[ind];
    }
    return res;
    
}

vector<string> Solution::prefix(vector<string> &A) {
   vector<string> res;
   
   if(A.size()==0)
    return res;
    
    Trie* root=new Trie();
    
    for(auto i : A)
        insertTrie(root,i);
    
    for(auto i:A)
        res.push_back(getPrefix(root,i));
    
    return res;
}
