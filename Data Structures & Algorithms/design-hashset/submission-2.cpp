class MyHashSet {
public:
    vector<bool> hashvec;
    MyHashSet() {
        hashvec.resize(1000001,false);
    }
    
    void add(int key) {
        hashvec[key]=true;
    }
    
    void remove(int key) {
        hashvec[key]=false;
    }
    
    bool contains(int key) {
       return hashvec[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */