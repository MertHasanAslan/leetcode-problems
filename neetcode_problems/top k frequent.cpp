class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> count_map;

        for (auto& num : nums){
            count_map[num]++;
        }
        
        for (int i = 0; i < k; i++){
            int max = 0;
            int key = INT_MIN;
            
            for (auto& m : count_map){
                if (m.second > max){
                    key = m.first;
                    max = m.second;
                }
            }
            count_map[key] = 0;
            res.push_back(key);
        }
        return res;
    }

};
