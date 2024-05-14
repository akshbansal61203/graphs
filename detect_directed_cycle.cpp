//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfscheck(int start,vector<int> adj[],vector<int>&vis,vector<int>&path){
        vis[start]=1;
        path[start]=1;
        for(auto it:adj[start]){
            if(!vis[it]){
               if( dfscheck(it,adj,vis,path))return true;
            }
            else if(vis[it]&&path[it]){
                return true;
            }
        }
        path[start]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int> vis(V,0);
       vector<int> path(V,0);
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfscheck(i,adj,vis,path)==true)return true;
           }
       }
       return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
