class Solution {
  public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        
        // 2D prefix sum
        vector<vector<long long>> ps(n+1, vector<long long>(m+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ps[i][j] = mat[i-1][j-1]
                         + ps[i-1][j]
                         + ps[i][j-1]
                         - ps[i-1][j-1];
            }
        }
        
        int count = 0;
        
        // try all top-left
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxSize = min(n-i, m-j);
                
                for(int s=1; s<=maxSize; s++){
                    int r2 = i + s;
                    int c2 = j + s;
                    
                    long long sum = ps[r2][c2]
                                  - ps[i][c2]
                                  - ps[r2][j]
                                  + ps[i][j];
                    
                    if(sum == x) count++;
                }
            }
        }
        
        return count;
    }
};