class MyHashSet {
public:
    vector<int> map;
    int size;
    
    MyHashSet() {
        size=1e6+1;
        map.resize(size);
    }
    
    
    void add(int key) {
        map[key]=1;
    }
    
    void remove(int key) {
        map[key]=0;
    }
    
    bool contains(int key) {
        return map[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */