#include<unordered_map>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> &adj,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontnode=q.front();
        q.pop();
        

        ans.push_back(frontnode);

        for(auto j: adj[frontnode]){
            if(!visited[j]){
                q.push(j);
                visited[j]=1;
            }
            
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int> > &adj){
    
    vector<int> ans;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(adj,visited,ans,i);
        }
        
    }
    return ans;
    
    
}
