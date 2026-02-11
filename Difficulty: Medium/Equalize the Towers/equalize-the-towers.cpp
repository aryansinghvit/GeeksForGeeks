class Solution {
public:
    long long minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int,int>> towers;

        for(int i = 0; i < n; i++)
            towers.push_back({heights[i], cost[i]});

        sort(towers.begin(), towers.end());

        long long totalCost = 0;
        for(auto &t : towers)
            totalCost += t.second;

        long long curr = 0;
        int targetHeight = 0;

        // Find weighted median
        for(auto &t : towers) {
            curr += t.second;
            if(curr * 2 >= totalCost) {
                targetHeight = t.first;
                break;
            }
        }

        // Calculate minimum cost
        long long ans = 0;
        for(auto &t : towers) {
            ans += 1LL * abs(t.first - targetHeight) * t.second;
        }

        return ans;
    }
};
