class Solution {
  public:
    bool isBitSet(int n) {
        return n == 0?false:((n+1)&n) == 0;
    }
};