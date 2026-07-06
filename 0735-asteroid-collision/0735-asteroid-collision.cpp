class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<pair<int,int>> s1;
        stack<pair<int,int>> s2;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0){
                s1.push({asteroids[i],i});
                while(!s1.empty() && ! s2.empty()){
                    if(abs(s1.top().first)>abs(s2.top().first) && s1.top().second<s2.top().second){
                        s2.pop();
                    }
                    else if(abs(s1.top().first)==abs(s2.top().first) && s1.top().second<s2.top().second){
                        s1.pop();
                        s2.pop();
                    }
                    else if(s1.top().second<s2.top().second){
                        s1.pop();
                    }
                    else{
                        break;
                    }
                    
                }
            }
            else{
                s2.push({asteroids[i],i});
                while(!s1.empty() && ! s2.empty()){
                    if(abs(s1.top().first)>abs(s2.top().first) && s1.top().second<s2.top().second){
                        s2.pop();
                    }
                    else if(abs(s1.top().first)==abs(s2.top().first) && s1.top().second<s2.top().second){
                        s1.pop();
                        s2.pop();
                    }
                    else if(s1.top().second<s2.top().second) {
                        s1.pop();
                    }
                    else{
                        break;
                    }
                    
                }
            }
        }
        while(!s1.empty() && !s2.empty()){
            if(s1.top().second>s2.top().second){
                ans.push_back(s1.top().first);
                s1.pop();
            }
            else{
                ans.push_back(s2.top().first);
                s2.pop();
            }
        }
        while(!s1.empty()){
            ans.push_back(s1.top().first);
            s1.pop();
        }
        while(!s2.empty()){
            ans.push_back(s2.top().first);
            s2.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};