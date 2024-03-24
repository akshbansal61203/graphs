class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &visited,int r,int c,int arr_row[],int arr_col[]){
            visited[r][c]=1;
            for(int i=0;i<4;i++){
                int nrow=r+arr_row[i];
                int ncol=c+arr_col[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]=='1'&& !visited[nrow][ncol])dfs(grid,visited,nrow,ncol,arr_row,arr_col);
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
                    dfs(grid,visited,i,j,arr_row,arr_col);
                }
            }
        }
        return count;
    }
};
