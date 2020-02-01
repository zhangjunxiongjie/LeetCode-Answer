/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
public:
    typedef struct 
    {
        int value;
        int counter; 
    }Value;
    
    map<int, Value> Cache; // 缓存。
    int CacheCapacity;
    int Counter; // 在寻找最小值时时间需要遍历整个 map 时间消耗较多，可以试着维护一个大小为 CacheCapacity 的循环队列。
    LRUCache(int capacity) {
        CacheCapacity = capacity; // 缓存容量。
        Counter = 0;
    }
    
    int get(int key) {
        Counter++;

        auto iter = Cache.find(key); 
        if(iter != Cache.end()){
            iter->second.counter = Counter; // 更新。
            return iter->second.value;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Counter++;

        auto iter = Cache.find(key);
        if (iter != Cache.end())
        {
            iter->second.value = value;
            iter->second.counter = Counter;
        }
        else
        {
            Value buffer{value, Counter};
            Cache.insert(map<int, Value>::value_type(key, buffer));
        }
        
        if (Cache.size() > CacheCapacity)
        {
            // 找到 counter 最小的一个。即是最久未使用的。
            auto CounterMin = Cache.begin();
            for (auto iter = Cache.begin(); iter != Cache.end(); iter++){
                if (iter->second.counter < CounterMin->second.counter){
                    CounterMin = iter;
                }
            }
            if (!Cache.empty()){
                Cache.erase(CounterMin);
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
// @lc code=end

