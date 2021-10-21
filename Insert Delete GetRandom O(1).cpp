class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        s.clear();
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end())
            return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end())
            return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        
        return *next(s.begin(),rand()%s.size()); //important STL
    }
};
