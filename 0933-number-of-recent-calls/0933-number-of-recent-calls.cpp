class RecentCounter {
public:
    int cnt;
    queue<int> q;
    RecentCounter() {
        cnt=0;
    }
    
    int ping(int t) {
        if(q.empty()){
            q.push(t);
        }
        else{
            q.push(t);
            while(!q.empty() && t-q.front()>3000){
                q.pop();
            }
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */