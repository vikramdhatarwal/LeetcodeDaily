class MyStack {
public:
    queue<int> q1;
    queue<int>q2;
    MyStack() {
        
    }
    
    void push(int x) {
        if(!q1.empty()){
            q1.push(x);
        }
        else{
            q2.push(x);
        }
    }
    
    int pop() {
        if(!q2.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            int poped= q2.front();
            q2.pop();
            return poped;
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int poped= q1.front();
            q1.pop();
            return poped;
        }
    }
    
    int top() {
        if(!q2.empty()){
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            int top= q2.front();
            q1.push(q2.front());
            q2.pop();
            return top;
        }
        else{
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            int top= q1.front();
            q2.push(q1.front());
            q1.pop();
            return top;
        }
    }
    
    bool empty() {
        if(q1.empty() && q2.empty()) return true;
        return false;
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