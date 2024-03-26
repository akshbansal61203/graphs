class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
         vector<vector<int>> dist(n,vector<int>(m,0));
         vector<vector<int>> vis(n,vector<int>(m,0));
         queue<pair<pair<int,int>,int>>q;
         int arr_row[4]={-1,0,1,0};
        int arr_col[4]={0,1,0,-1};
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    vis[i][j]=1;
                    q.push({{i,j},0});//multi spource bfs
                }
            }
         }
         int dm=0;
         while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dist[r][c]=d;
            for(int i=0;i<4;i++){
                int nrow=r+arr_row[i];
                int ncol=c+arr_col[i];
                if(nrow>=0 && nrow<mat.size() && ncol>=0 && ncol<mat[0].size() && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                }
            }
         }
         return dist;
    }
};
