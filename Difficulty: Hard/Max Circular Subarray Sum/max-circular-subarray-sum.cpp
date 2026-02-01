class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxKadane = kadane(arr); // standard max subarray sum
        int total = 0;

        // invert array to find min subarray sum using Kadane
        vector<int> invArr = arr;
        for(int i = 0; i < n; i++) {
            total += arr[i];
            invArr[i] = -arr[i];
        }

        int maxInverseKadane = kadane(invArr); // max sum of -arr = -min sum of arr
        int maxWrap = total + maxInverseKadane; // total - minSum

        // handle all negative numbers
        if(maxWrap == 0)
            return maxKadane;

        return max(maxKadane, maxWrap);
    }

private:
    int kadane(const vector<int>& nums) {
        int maxEndingHere = nums[0], maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
