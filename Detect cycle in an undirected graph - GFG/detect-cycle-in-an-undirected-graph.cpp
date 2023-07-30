//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detectBFS(int src,vector<int> adj[],int vis[]){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjElement: adj[node]){
                if(!vis[adjElement]){
                    q.push({adjElement,node});
                    vis[adjElement]=1;
                }
                else if(parent!=adjElement){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool detectDFS(int node,int parent,int vis[],vector<int> adj[]){
        vis[node]=1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                if(detectDFS(adjNode,node,vis,adj)==true) return true;
            }
            else if(parent!= adjNode) return true;
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectDFS(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends