class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;
        for (int i = 0; i < strs.size(); i++) {
        string original = strs[i];       
        string key = original;          
        sort(key.begin(), key.end());   
        hashtable[key].push_back(original); 
        }
        vector<vector<string>> result;
        for (auto& pair : hashtable) {
            result.push_back(pair.second);
        }
        return result;
    }
};
