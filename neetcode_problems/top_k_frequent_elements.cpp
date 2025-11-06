class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<vector<int>> freq(nums.size()+1);
        vector<int> result;

        for (int i : nums){
            m[i] = 1+m[i];
        }

        for(auto pair : m){
            freq[pair.second].push_back(pair.first);
        }

        for(int i = nums.size(); i>0; i--){
            for(int j : freq[i]){
                result.push_back(j);
                if (result.size() == k){
                    return result;
                }
            }
        }
        return result;
    }
};
