class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        unordered_map<int, int> firstIndex;
        
        int prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            prefix += (a1[i] - a2[i]);

            if (prefix == 0) {
                maxLen = i + 1;
            }

            if (firstIndex.find(prefix) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            } else {
                firstIndex[prefix] = i;
            }
        }

        return maxLen;
    }
};