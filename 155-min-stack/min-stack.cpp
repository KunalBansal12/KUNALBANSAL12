class MinStack {
public:
    stack<int> s,smin;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(smin.empty()) smin.push(val);
        else if(smin.top()>=val){
            smin.push(val);
        }
    }
    
    void pop() {
        int t=s.top();
        s.pop();
        if(t==smin.top()) smin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return smin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */