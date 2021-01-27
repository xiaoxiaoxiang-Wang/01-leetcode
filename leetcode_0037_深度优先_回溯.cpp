class Solution {
public:
    // 区块 横轴 纵轴 共三个大区域 
    bool b[9][9],h[9][9],w[9][9];
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]!='.') {
                    b[i/3*3+j/3][board[i][j]-'1'] = true;
                    h[j][board[i][j]-'1'] = true;
                    w[i][board[i][j]-'1'] = true;
                }
            }
        }
        solve(0,board);      
    }
    
    bool solve(int index,vector<vector<char>>& board) {
        if(index==81) {
            return true;
        }
        int i = index/9;
        int j = index%9;
        if(board[i][j]!='.') {
            return solve(index+1,board);
        }              
        for(int k=0;k<9;k++) {
            if(!(b[i/3*3+j/3][k]||h[j][k]||w[i][k])) {
                board[i][j]='1'+ k; 
                b[i/3*3+j/3][k]=true;
                h[j][k]=true;
                w[i][k]=true;
                if(solve(index+1,board)){
                    return true;
                }
                board[i][j]='.'; 
                b[i/3*3+j/3][k]=false;
                h[j][k]=false;
                w[i][k]=false;  
            }            
        }
        return false;
    }
};