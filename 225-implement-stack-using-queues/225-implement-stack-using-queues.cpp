class MyStack {
public:
    
    queue<int> q;
    int size;
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int s=q.size();
        s--;
        while(s--){
            int temp=q.front();
            q.push(temp);
            q.pop();
        }
        
        int temp=q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */