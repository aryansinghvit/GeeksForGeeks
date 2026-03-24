class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Push all rotten and count fresh
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 2) {
                    q.push({i, j});
                }
                else if(mat[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int time = 0;
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        
        // BFS
        while(!q.empty() && fresh > 0) {
            int size = q.size();
            time++;
            
            for(int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    
                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        if(fresh > 0) return -1;
        
        return time;
    }
};