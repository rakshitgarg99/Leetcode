class Solution {
public:
    
    
    void gameOfLife(vector<vector<int>>& board) {
        int d[][2] = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
        int m=board.size(), n=board[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live = 0;
                for(int k=0;k<8;k++){
                    int x= d[k][0]+i;
                    int y= d[k][1]+j;
                    
                    if(x>-1 and y>-1 and x<m and y<n){
                        if(board[x][y] & 1){live++;}
                    }
                }
                
                if(board[i][j]==0){
                    if(live==3){ board[i][j]=2;}
                }
                
                else{
                    if(live < 2 || live > 3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=3;
                    }
                }
                
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j=0; j < board[0].size(); j++){
                board[i][j] >>=1;
            }
        }

    }
};