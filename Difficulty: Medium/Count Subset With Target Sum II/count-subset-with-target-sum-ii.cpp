class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size();
        int mid = n / 2;

        vector<long long> leftSums, rightSums;

        // Left half subset sums
        for (int mask = 0; mask < (1 << mid); mask++) {
            long long sum = 0;
            for (int i = 0; i < mid; i++) {
                if (mask & (1 << i))
                    sum += arr[i];
            }
            leftSums.push_back(sum);
        }

        // Right half subset sums
        for (int mask = 0; mask < (1 << (n - mid)); mask++) {
            long long sum = 0;
            for (int i = 0; i < n - mid; i++) {
                if (mask & (1 << i))
                    sum += arr[mid + i];
            }
            rightSums.push_back(sum);
        }

        sort(rightSums.begin(), rightSums.end());

        int count = 0;
        for (long long x : leftSums) {
            long long target = k - x;
            count += upper_bound(rightSums.begin(), rightSums.end(), target)
                   - lower_bound(rightSums.begin(), rightSums.end(), target);
        }

        return count;
    }
};
