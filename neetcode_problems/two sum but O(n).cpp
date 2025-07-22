class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++){
            if (map.count(target - nums[i]) > 0){
                return {min(i, map[target-nums[i]]), max(i, map[target-nums[i]])};
            }
            map[nums[i]] = i;
        }
    }
};
