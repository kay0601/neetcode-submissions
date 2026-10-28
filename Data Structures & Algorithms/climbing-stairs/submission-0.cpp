class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        vector<int> ways(n + 1);
        ways[1] = 1; // 走到第 1 階
        ways[2] = 2; // 走到第 2 階

        for (int i = 3; i <= n; ++i) {
            ways[i] = ways[i - 1] + ways[i - 2]; // 走 1 階上來 或 走 2 階上來
        }

        return ways[n];
    }
};