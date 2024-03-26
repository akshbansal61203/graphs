class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        int arr_row[4]={-1,0,1,0};
        int arr_col[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=true;
                board[i][0]='y';
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                board[i][m-1]='y';
                vis[i][m-1]=true;
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                vis[0][i]=true;
                board[0][i]='y';
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                board[n-1][i]='y';
                q.push({n-1,i});
                vis[n-1][i]=true;
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+arr_row[i];
                int ncol=c+arr_col[i];
                if(nrow<n && nrow>=0 && ncol<m &&ncol>=0 && board[nrow][ncol]=='O'&&!vis[nrow][ncol]){
                    board[nrow][ncol]='y';
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='y')board[i][j]='O';
            }
        }
    }
};
