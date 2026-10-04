class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;                  // 左手食指指著第一個位子 (Index 0)
        int right = nums.size() - 1;   // 右手食指指著最後一個位子

        // 當左手還沒越過右手的時候，代表還有數字可以找
        while (left <= right) {
            
            // 找出左右手中間的位子
            int mid = left + (right - left) / 2; 
            
            // 情況 1：太幸運了，中間這個數字剛好就是我們要找的！
            if (nums[mid] == target) {
                return mid;  // 回傳它所在的位子 (Index)
            }
            // 情況 2：中間的數字「太小了」
            else if (nums[mid] < target) {
                // 代表答案一定在「右半邊」，所以把左手移到 mid 的右邊一格
                left = mid + 1;
            }
            // 情況 3：中間的數字「太大了」
            else {
                // 代表答案一定在「左半邊」，所以把右手移到 mid 的左邊一格
                right = mid - 1;
            }
        }
        
        // 如果迴圈結束了 (左手越過右手)，代表整個陣列都找過了還是沒有
        return -1; 
    }
};