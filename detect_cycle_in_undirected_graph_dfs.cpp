//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
   bool detect_dfs(int src,vector<int> adj[],int vis[],int n){
       vis[src]=1;//n is parent noode
       for(auto adjNode:adj[src]){
           if(!vis[adjNode]){
              if( detect_dfs(adjNode,adj,vis,src))return true;
           }
           else{
               if(n!=adjNode){
                   return true;
               }
           }
           
       }
       
         return false;
   }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect_dfs(i,adj,vis,-1))return true;
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
