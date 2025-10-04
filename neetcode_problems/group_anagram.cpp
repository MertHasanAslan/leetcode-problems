class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;

        for (auto str : strs){
            string str_org = str;
            sort(str.begin(), str.end());
            map[str].push_back(str_org);
        }

        for (auto pair : map){
            res.push_back(pair.second);
        }
        return res;
    }
};
