class MyHashSet {
public:
    vector<int> hashvec;
    MyHashSet() {
        hashvec.resize(1000001,0);
    }
    
    void add(int key) {
        hashvec[key]=1;
    }
    
    void remove(int key) {
        hashvec[key]=0;
    }
    
    bool contains(int key) {
        if(hashvec[key])
        return true;
        else
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */