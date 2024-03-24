class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int color,int inicolor,vector<vector<int>>& ans,int arr_row[], int arr_col[]) {
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+arr_row[i];
            int ncol=col+arr_col[i];
            if(nrow<n && nrow>=0 && ncol<m &&ncol>=0 && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,image,color,inicolor,ans,arr_row,arr_col);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor=image[sr][sc];
        vector<vector<int>> ans=image;
        int arr_row[4]={-1,0,1,0};
        int arr_col[4]={0,1,0,-1};
        dfs(sr,sc,image,color,inicolor,ans,arr_row,arr_col);
        return ans;
    }
};
