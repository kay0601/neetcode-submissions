class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashtable;
        for(int i = 0; i<nums.size();i++){
            if(hashtable.contains(target - nums[i])){
                return {hashtable[target - nums[i]], i};
            }
            else{
                hashtable[nums[i]]=i;
            }
        }
    }
};
