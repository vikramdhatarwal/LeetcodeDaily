class Solution {
public:
    bool detectCycle(int node , vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& path, vector<bool>& check){
        visited[node]= true;
        path[node]= true;
        check[node]= false;
        for(int x: graph[node]){
            if(!visited[x]){
                if(detectCycle(x,graph,visited,path,check)){
                    check[x]=false;
                    return true;
                }
            }
            else{
                if(path[x]){
                    check[x]=false;
                    return true;
                } 
            }
        }
        path[node]= false;
        check[node]=true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        vector<bool> check(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                detectCycle(i,graph,visited,path,check);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==true){
                ans.push_back(i);
            }
        }
        return ans;

    }
};