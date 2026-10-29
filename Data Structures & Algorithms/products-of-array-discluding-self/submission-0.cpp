class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> output(n);

        // 1. 計算左側乘積（從左走到右）
        int curr = 1; // 袋子初始值為 1
        for (int i = 0; i < n; i++) {
            left[i] = curr;     // 先把左邊累積的乘積交給當前位置
            curr *= nums[i];    // 再把當前數字吃進袋子，準備給下一位用
        }

        // 2. 計算右側乘積（從右走到左）
        curr = 1; // 袋子重置為 1
        for (int i = n - 1; i >= 0; i--) {
            right[i] = curr;    // 先把右邊累積的乘積交給當前位置
            curr *= nums[i];    // 再把當前數字吃進袋子，準備給左邊下一位用
        }

        // 3. 把兩邊的結果乘起來就是答案
        for (int i = 0; i < n; i++) {
            output[i] = left[i] * right[i];
        }

        return output;
    }
};