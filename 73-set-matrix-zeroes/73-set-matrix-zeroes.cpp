class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        // int d[][2] = {{1,-1}, {1,0}, {1,-1}, {0,-1}, {0,1}, {-1,1},{-1,0},{-1,-1}};
        vector<pair<int,int>> d;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    
                    // for(int i=0;i<m;i++){
                    //     matrix[i][j]=0;
                    // }
                    // for(int j=0;j<n;j++){
                    //     matrix[i][j]=0;
                    // }
                    d.push_back({i,j});
                }
            }
        }
        // cout<<d.size();
        for(int x=0;x<d.size();x++){
            // cout<<d[x].first<<" "<<d[x].second<<endl;
            for(int i=0;i<m;i++){
                matrix[i][d[x].second]=0;
            }
            for(int j=0;j<n;j++){
                matrix[d[x].first][j]=0;
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         matrix[i][j]>>=1;
        //     }
        // }
    }
};