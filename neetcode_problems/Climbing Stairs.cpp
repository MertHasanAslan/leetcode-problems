class Solution {
    unordered_map<int, int> map;
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1){
            return 1;
        }
        if (map.count(n)) { return map[n]; }
        else{
            return map[n] = climbStairs(n-1) + climbStairs(n-2);
        }
    }
};
