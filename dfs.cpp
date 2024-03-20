#include<unordered_map>
#include<queue>
using namespace std;
void dfs(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited,vector<int> &component, int node){
    visited[node]=true;
    component.push_back(node);
    
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj,visited,component,i);
        }
    }
    
} 
vector<vector<int> > depthFirstSearch(int V, int E,vector<vector<int>> &edges) {
    unordered_map<int, list<int>> adj;
    vector<vector<int> > ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    for (int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
        
    }
    return ans;
}