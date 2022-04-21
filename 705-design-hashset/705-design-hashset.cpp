class MyHashSet {
public:
    vector<list<int>> map;
    int size;
    
    MyHashSet() {
        size=1e6+1;
        map.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<int>:: iterator search(int key){
        int i=hash(key);
        return find(map[i].begin(), map[i].end(), key);
    }
    
    void add(int key) {
        if(contains(key)) return ;
        int i=hash(key);
        map[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
        int i=hash(key);
        map[i].erase(search(key));
        
    }
    
    bool contains(int key) {
        int i=hash(key);
        if(search(key) != map[i].end()) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */