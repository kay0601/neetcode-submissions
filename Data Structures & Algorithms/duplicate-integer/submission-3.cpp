class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashtable;
        for(int i=0; i<nums.size(); i++){
            if(hashtable.contains(nums[i])){
                return true;
            }
            else{
                hashtable.insert(nums[i]);
            }
        }
        return false;
    }
};