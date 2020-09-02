//Phoenix_RK


/*

https://practice.geeksforgeeks.org/problems/lru-cache/1


The task is to design and implement methods of an LRU cache. The class has two methods get() and set() which are defined as follows.
get(x)   : Returns the value of the key x if the key exists in the cache otherwise returns -1.
set(x,y) : inserts the value if the key x is not already present. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the size of the cache should be intitialized.

Example 1:

Input:
N = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: Cache Size = 2
SET 1 2 GET 1
SET 1 2 : 1 -> 2
GET 1 : Print the value corresponding
to Key 1, ie 2.
Example 2:

Input:
N = 2
Q = 7
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 GET 1
Output: 5 -1
Explanation: Cache Size = 2
SET 1 2 SET 2 3 SET 1 5 SET 4 5
SET 6 7 GET 4 GET 1
SET 1 2 : 1 -> 2
SET 2 3 : 1 -> 2, 2 -> 3 (the most
recently used one is kept at the
rightmost position) 
SET 1 5 : 2 -> 3, 1 -> 5
SET 4 5 : 1 -> 5, 4 -> 5 (Cache size
is 2, hence we delete the least
recently used key-value pair)
SET 6 7 : 4 -> 5, 6 -> 7 
GET 4 : Prints 5
GET 1 : No key-value pair having
key = 1. Hence prints -1.
Your Task:
You only need to complete the provided functions get() and set(). 

Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). (though, you may use extra space for cache storage and implementation purposes).








*/

// design the class:

class LRUCache
{
public:
    list<pair<int,int>> q;
    unordered_map<int,list<pair<int,int>> ::iterator> m;
    int capacity;
    LRUCache(int cap)
    {
        // constructor for cache
       capacity=cap;
       q.clear();
       m.clear();
    }
    
 int get(int key)
    {
        // this function should return value corresponding to key
        
        if(m.find(key)==m.end())
            return -1;
        
        auto it=m.find(key); //this gives the iterator (ie) the position of key in map
        int val=(*(it->second)).second; //this gives the value for the key
        q.erase(it->second);  //it->second is the iterator which gives the position of the key in the map
        q.push_front({key,val});
        m[key]=q.begin();
        return val;
    }
    
 void set(int key, int value)
    {
        // storing key, value pair
        
        if(m.find(key)==m.end())//if not present, have to insert 
        {
            if(q.size()==capacity)//if the cache size is full, remove the least recently used
            {
                int lx= q.back().first;
                q.pop_back();
                m.erase(lx);
                
                q.push_front({key,value});
                m[key]=q.begin();
            }
            else//if cache not full, just insert
            {
                q.push_front({key,value});
                m[key]=q.begin();
            }
        }
        else
        {
            //if already present then modify the position
            auto it = m.find(key);
            q.erase(it->second);
            q.push_front({key,value});
            m[key]=q.begin();
        }
     

    }
};
