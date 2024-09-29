class AllOne {
public:
    unordered_map<string,int> map;
    set<pair<int,string>> s;
    AllOne() {
        
    }
    
    void inc(string key) {
        int val=map[key];
        if(val>0){
            s.erase({val,key});
        }
        map[key]++;
        s.insert({val+1,key});
    }
    
    void dec(string key) {
        int val=map[key];
        if(val>0){
            s.erase({val,key});
            map[key]--;
        }
        if(val-1>0) s.insert({val-1,key});
    }
    
    string getMaxKey() {
        if(s.size()==0) return "";
        auto it=s.end();
        it--;
        pair<int,string> p=*it;
        return p.second;
    }
    
    string getMinKey() {
        if(s.size()==0) return "";
        auto it=s.begin();
        pair<int,string> p=*it;
        return p.second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */