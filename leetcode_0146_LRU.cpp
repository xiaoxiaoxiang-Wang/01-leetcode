class LRUCache {
    unordered_map<int,list<pair<int,int>>::iterator> data;
    list<pair<int,int>> cache;
    int capacity_;
public:
    LRUCache(int capacity):capacity_(capacity) {
    }
    
    int get(int key) {
        auto it = data.find(key);
        if(it==data.end()) {
          return -1;
        }
        // 把当前元素置于首位
        cache.splice(cache.begin(),cache,it->second);
        return it->second->second;

    }
    
    void put(int key, int value) {
        auto it = data.find(key);
        if(it!=data.end()) {
            cache.splice(cache.begin(),cache,it->second);
            it->second->second = value;
        } else {
            cache.push_front(make_pair(key,value));
            data[key] = cache.begin();
            if(data.size()>capacity_) {
              data.erase(cache.rbegin()->first);
              cache.pop_back();
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */