class Solution {
public:
    long long digitSum(long long x) {
        long long s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    long long getCount(long long n, long long d) {
        long long start = -1;

        // search only near d (digit sum ≤ 81)
        for (long long x = max(1LL, d); x <= n && x <= d + 100; x++) {
            if (x - digitSum(x) >= d) {
                start = x;
                break;
            }
        }

        if (start == -1) return 0;
        return n - start + 1;
    }
};
