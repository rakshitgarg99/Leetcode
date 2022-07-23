class LRUCache {
public:
    
    
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> address;
    list<int> l;
    
    int cap, siz;
    LRUCache(int capacity) {
        cap=capacity;
        siz=0;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            auto it=address[key];
            l.erase(it);
            address.erase(key);
            
            l.push_front(key);
            address[key]=l.begin();
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            siz--;
        }
        
        if(siz==cap){
            int k=l.back();
            l.pop_back();
            address.erase(k);
            mp.erase(k);
            siz--;
        }
        
        l.push_front(key);
        mp[key]=value;
        address[key]=l.begin();
        siz++;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */