class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i=0; i<nums.size();i++){
            int kk = target - nums[i];
            if(hashmap.contains(kk)){
                return {hashmap[kk],i};
            }
            hashmap[nums[i]] = i;
        }
        
    }
};
