class Solution {
private:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> validP(m,vector<bool>(n,false));
        vector<vector<bool>> validA(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) {
            dfs(heights,m,n,0,i,0,validP);
            dfs(heights,m,n,0,i,n-1,validA);
        }
        for(int j=0;j<n;j++) {
            dfs(heights,m,n,0,0,j,validP);
            dfs(heights,m,n,0,m-1,j,validA);
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(validP[i][j]&&validA[i][j]) {
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& heights,int& m,int& n,int val,int h,int w,vector<vector<bool>>& valid){
        if(h<0||h>=m||w<0||w>=n||valid[h][w]||heights[h][w]<val) {
            return;
        }        
        
        valid[h][w] = true;    
        for(int i=0;i<4;i++) {
            dfs(heights,m,n,heights[h][w],h+dir[i][0],w+dir[i][1],valid);
        }
    }
    
};