class Solution {
public:
    bool detectCycle(int node , vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path){
        visited[node]= true;
        path[node]= true;
        for(int x: adj[node]){
            if(!visited[x]){
                if(detectCycle(x,adj,visited,path)){
                    return true;
                }
            }
            else{
                if(path[x]) return true;
            }
        }
        path[node]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u= prerequisites[i][1];
            int v= prerequisites[i][0];
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(detectCycle(i,adj,visited,path)) {
                    return false;
                }
                
            }
        }
        return true;
    }
};