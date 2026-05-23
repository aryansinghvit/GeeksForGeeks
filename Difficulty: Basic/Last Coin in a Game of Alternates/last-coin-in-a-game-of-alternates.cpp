class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int low = arr[0];
        int n = arr.size();
        for(int i=1;i<arr.size(); i++){
            low = min(arr[i], low);
        }
        return low;
    }
};