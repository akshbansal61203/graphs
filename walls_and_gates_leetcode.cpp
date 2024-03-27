#include <bits/stdc++.h> 
#define INF 2147483647
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>>q;
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                vis[i][j]=true;
                q.push({{i, j}, 0});
            }
        }
    }
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int d=q.front().second;
        a[r][c]=d;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+row[i];
            int ncol=c+col[i];
            if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&a[nrow][ncol]==INF&&!vis[nrow][ncol]){
                vis[nrow][ncol]=true;
                q.push({{nrow,ncol},d+1});
            }
        }
    }
    return a;
}
