class Solution {
  public:
    vector<int> diagView(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> result;

        for (int sum = 0; sum <= 2 * (n - 1); sum++) {
            for (int i = 0; i < n; i++) {
                int j = sum - i;
                if (j >= 0 && j < n) {
                    result.push_back(mat[i][j]);
                }
            }
        }

        return result;
    }
};