class StockSpanner {
public:
    vector<int> pge;
    stack<pair<int,int>> s; // {price, index}
    StockSpanner() {
    }

    int next(int price) {
        while(!s.empty() && s.top().first <= price){
            s.pop();
        }
        if(s.empty())
            pge.push_back(-1);
        else
            pge.push_back(s.top().second);
        s.push({price, (int)pge.size()-1});
        int idx = pge.size()-1;
        return idx - pge.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */