class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s : strs) {
            encoded += to_string(s.length()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0; // 指標 1：停在長度數字的地方

        while (i < s.length()) {
            // 指標 2：從 i 開始往後找到第一個 '#' 的位置
            int j = s.find('#', i);

            // 截取數字字串並轉成整數長度
            int len = stoi(s.substr(i, j - i));

            // 從 '#' 後一格 (j + 1) 開始，往後取 len 個字元
            string str = s.substr(j + 1, len);
            res.push_back(str);

            // 抓完之後，把指標 1 移動到下一個單詞的數字起點
            i = j + 1 + len;
        }
        return res;
        }
};
