class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int sum = 0, bsum = 0;
        for(int &i:arr)sum+=i;
        for(int &i:arr){
            bsum+=i;
            if(sum - 2*bsum == 0)return true;
        }
        return false;
    }
};