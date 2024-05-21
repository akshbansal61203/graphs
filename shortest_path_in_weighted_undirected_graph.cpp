//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)parent[i]=i;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;
                if(d+wt<dist[v]){
                    dist[v]=d+wt;
                    pq.push({dist[v],v});
                    parent[v]=node;
                }
            }
        }
        if(dist[n]==1e9)return {-1};
        vector<int>ans(n+1);
        int node=n;
        ans[0]=dist[n];
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin()+1,ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends
