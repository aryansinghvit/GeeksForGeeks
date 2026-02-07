class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();

        int arrSum = 0;
        int currVal = 0;

        // Initial sum and initial configuration
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            currVal += i * arr[i];
        }

        int maxVal = currVal;

        // Compute values for remaining rotations
        for (int i = 1; i < n; i++) {
            currVal = currVal + arrSum - n * arr[n - i];
            maxVal = max(maxVal, currVal);
        }

        return maxVal;
    }
};
