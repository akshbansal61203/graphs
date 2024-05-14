//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool dfscheck(int start,vector<int>&vis,vector<int>&path,vector<int> adj[],vector<int>&check){
      vis[start]=1;
      path[start]=1;
      check[start]=0;
      for(auto it:adj[start]){
          if(!vis[it]){
              if(dfscheck(it,vis,path,adj,check))return true;
          }
          else if(path[it]){
              return true;
          }
      }
      check[start]=1;
      path[start]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfscheck(i,vis,path,adj,check);
            }
        }
        vector<int> safe_nodes;
        for(int i=0;i<V;i++){
            if(check[i]==1)safe_nodes.push_back(i);
        }
        return safe_nodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
