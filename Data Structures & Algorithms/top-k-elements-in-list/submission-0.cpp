class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            hashtable[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& pair : hashtable) {
        int num = pair.first;   
        int freq = pair.second; 
        buckets[freq].push_back(num);
        }
        vector<int> result;

        for (int i = buckets.size() - 1; i >= 0; i--) {
        for (int num : buckets[i]) {
            result.push_back(num); 

            if (result.size() == k) {
                return result;
                }
            }
        }
    }
};
