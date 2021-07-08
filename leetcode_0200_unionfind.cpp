class Solution {
public:
    int index=2;
    int union_size=0;
    int numIslands(vector<vector<char>>& grid) {        
        int height = grid.size();
        if(height==0) {
            return 0;
        }
        int width = grid[0].size();
        vector<int> v(width*height,0);
        vector<vector<int>> g(height,vector<int>(width,0));
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                if(grid[i][j]=='0') {
                    continue;
                }
                isConnect(g,v,i,j);
            }
        }
        return index-2-union_size;
    }
    
    void isConnect(vector<vector<int>>& grid,vector<int>& v,int i,int j) {
        int hPrev = getHPrev(grid,i,j);
        int wPrev = getWPrev(grid,i,j);
        if(hPrev==0&&wPrev==0) {
            grid[i][j]=index++;
        }else if(hPrev>0&&wPrev>0) {
            if(hPrev==wPrev) {
                grid[i][j]=hPrev;
            } else {
                if(unionFind(v,hPrev,wPrev)) {
                    union_size++;
                }
                grid[i][j]=min(hPrev,wPrev);
            }           
        }else {
            grid[i][j] = max(hPrev,wPrev);
        }
        
    }
    
    int getHPrev(vector<vector<int>>& grid,int i,int j) {
        if(i==0) {
            return 0;
        } else {
            return grid[i-1][j];
        } 
    }
    
    int getWPrev(vector<vector<int>>& grid,int i,int j) {
        if(j==0) {
            return 0;
        } else {
            return grid[i][j-1];
        } 
    }
    
    int find(vector<int>& v,int i) {
        while(v[i]!=0) {
            i=v[i];
        }
        return i;
    }
    
    bool unionFind(vector<int>& v,int i,int j) {     
        i=find(v,i);
        j=find(v,j);
        if(i==j) {         
            return false;
        }
        v[i]=j;
        return true;
    }
};