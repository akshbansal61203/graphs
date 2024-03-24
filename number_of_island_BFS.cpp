class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>> &visited,int r,int c,int arr_row[],int arr_col[]){
            visited[r][c]=1;
            queue<pair<int,int>>qu;
            qu.push({r,c});
            while(!qu.empty()){
                int row=qu.front().first;
                int col=qu.front().second;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+arr_row[i];
                    int ncol=col+arr_col[i];
                    if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1'&& !visited[nrow][ncol]){
                        visited[nrow][ncol]=1;
                        qu.push({nrow,ncol});
                    }
                }
            }
            
            
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count=0;
         int arr_row[4]={-1,0,1,0};
        int arr_col[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    count++;
                    bfs(grid,visited,i,j,arr_row,arr_col);
                }
            }
        }
        return count;
    }
};
