class Solution {
public:
    int tm=0;
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //{{r,c},t}
        int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        //BFS starts
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            vis[r][c]=2;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<vis.size()&&ncol<vis[0].size()&&grid[nrow][ncol]==1&&!vis[nrow][ncol]){
                    q.push({{nrow,ncol},t+1});//push those who are now rotten
                    vis[nrow][ncol]=2;//to simultaneously make it visited
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1)return -1;
            }
        }
        return tm;
    }
};
