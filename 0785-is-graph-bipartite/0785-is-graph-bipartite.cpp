class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color, int node){
        stack<int> s;
        s.push(node);
        color[node]=0;
        while(!s.empty()){
            int curr_node= s.top();
            int curr_col= color[curr_node];
            s.pop();
            for(int x : graph[curr_node]){
                if(color[x]==-1){
                    color[x]= 1-curr_col;
                    s.push(x);
                }
                else{
                    if(color[x]==curr_col) return true;
                }
            }

        }
        return false;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(graph,color,i)) return false;
            }
        }
        return true;


    }
};