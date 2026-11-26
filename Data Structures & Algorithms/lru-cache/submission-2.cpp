class Node{
    public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int v,int k)
    {
        val=v;
        key=k;
        next=nullptr;
        prev=nullptr;
    }
};
class LRUCache {
public:
    int cap;
    Node* left;
    Node* right;
    unordered_map<int,Node*> cache;
    LRUCache(int capacity) {
       cap=capacity; 
       left=new Node(0,0);
       right=new Node(0,0);
       left->next=right;
       right->prev=left;
    }
    void remove(Node* p)
    {
        Node* back=p->prev;
        Node* front=p->next;
        back->next=front;
        front->prev=back;
    }
    void insert(Node* p)
    {
        Node* back=right->prev;
        p->prev=back;
        back->next=p;
        p->next=right;
        right->prev=p;
    }
    int get(int key) {
        if(cache.find(key)!=cache.end())
        {
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end())
        {
            cache[key]->val=value;
            remove(cache[key]);
            insert(cache[key]);
        }
        else
        {
            cache[key]=new Node(value,key);
            insert(cache[key]);
            if(cache.size()>cap)
            {
                cache.erase(left->next->key);
                remove(left->next);
            }
        }
    }
};
