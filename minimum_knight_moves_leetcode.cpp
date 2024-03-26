int minimumKnightMoves(int x, int y) {
    // Write your code here
     x+=110;
     y+=110;//to make proper space
    vector<vector<bool>> vis(300, vector<bool>(300,false));
    vector<vector<int>> dir = { {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };
    queue<pair<pair<int,int>,int>>q;
    vis[110][110]=true;
    q.push({{110,110},0});
    int s=0;
    while(!q.empty()){
         int r=q.front().first.first;
         int c=q.front().first.second;
         int step=q.front().second;
    
         if(x==r&&y==c)return step;
        q.pop();
        for(auto el:dir){
            int nrow=r+el[0];
            int ncol=c+el[1];
            if(nrow>=0&&ncol>=0&&nrow<300&&ncol<300&&vis[nrow][ncol]==false){
                vis[nrow][ncol]=true;
                q.push({{nrow,ncol},step+1});
            }
        }
    }
    return -1;
}
