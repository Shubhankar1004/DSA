//using BFS approach


class Solution {
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dir[5]={-1,0,1,0,-1};
        int t=0;
        while(!q.empty()){
            int sz=q.size();
            bool f=false;
            while(sz--){
                auto p=q.front();
                q.pop();
                int x=p.first,y=p.second;
                for(int i=0;i<4;i++){
                        int r=x+dir[i];
                        int c=y+dir[i+1];
                        if( r>=0 and c>=0 and r<n and c<m and grid[r][c]==1){
                            q.push({r,c});
                            grid[r][c]=2;
                            f=true;
                        }
                    }
                }
            if(f){
                t++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};
