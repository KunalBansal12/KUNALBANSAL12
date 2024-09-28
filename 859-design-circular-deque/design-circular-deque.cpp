class MyCircularDeque {
public:
queue<int> q;
int siz;
    MyCircularDeque(int k) {
        siz=k;
    }
    
    bool insertFront(int value) {
        if(q.size()==siz) return false;
        int n=q.size();
        q.push(value);
        for(int i=0;i<n;i++){
            int l=q.front();
            q.pop();
            q.push(l);
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(q.size()==siz) return false;
        q.push(value);
        return true;
    }
    
    bool deleteFront() {
        if(q.size()==0) return false;
        q.pop();
        return true;
    }
    
    bool deleteLast() {
        if(q.size()==0) return false;
        int l=q.size();
        for(int i=0;i<l-1;i++){
            int n=q.front();
            q.pop();
            q.push(n);
        }
        q.pop();
        return true;
    }
    
    int getFront() {
        if(q.size()==0) return -1;
        return q.front();
    }
    
    int getRear() {
        if(q.size()==0) return -1;
        int l=q.size(),k=0;
        for(int i=0;i<l;i++){
            k=q.front();
            q.pop();
            q.push(k);
        }
        return k;
    }
    
    bool isEmpty() {
        return q.size()==0;
    }
    
    bool isFull() {
        return q.size()==siz;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */