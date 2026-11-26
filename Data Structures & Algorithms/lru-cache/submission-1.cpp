class Node{
    public:
    int key;
    int val;
    Node* back;
    Node* next;
    Node(int k,int v)
    {
        this->key=k;
        this->val=v;
        this->back=nullptr;
        next=nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> cache;
    int cap=0;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        cap=capacity;
        left=new Node(0,0);
        right=new Node(0,0);
        left->next=right;
        right->back=left;
    }
    void remove(Node* node)
    {
        Node* prev=node->back;
        Node* front=node->next;
        prev->next=front;
        front->back=prev;
    }
    void insert(Node* node)
    {
        Node* prev=right->back;
        node->back=prev;
        node->next=right;
        right->back=node;
        prev->next=node;
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
            cache[key]=new Node(key,value);
            insert(cache[key]);
            if(cache.size()>cap)
            {
                cache.erase(left->next->key);
                remove(left->next);
            }
        }
    }
};
