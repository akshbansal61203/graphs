//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(vector<int>&vis,vector<pair<int,int>>adj[],int src,stack<int>&st){
        vis[src]=1;
        for(auto it:adj[src]){
            int v=it.first;
            if(!vis[v])dfs(vis,adj,v,st);
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       vector<pair<int,int>> adj[N];
       for(int i=0;i<M;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           int wt=edges[i][2];
           adj[u].push_back({v,wt});
       }
       stack<int>st;
       vector<int>vis(N,0);
       vector<int>dist(N,1e9);
       for(int i=0;i<N;i++){
           if(!vis[i]){
               dfs(vis,adj,i,st);
           }
       }
       dist[0]=0;
       while(!st.empty()){
           int node=st.top();
           st.pop();
           for(auto it:adj[node]){
               int v=it.first;
               int wt=it.second;
               if(dist[node]+wt<dist[v]){
                   dist[v]=dist[node]+wt;
               }
           }
       }
       for(int i=0;i<N;i++){
           if(dist[i]==1e9)dist[i]=-1;
       }
       return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
