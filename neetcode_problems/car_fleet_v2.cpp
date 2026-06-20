class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> times;
        vector<pair<int, int>> pairs;
        // add pairs
        for (int i = 0; i < position.size(); i++){
            pairs.push_back({position[i], speed[i]});
        }

        // sort pairs
        sort(pairs.begin(), pairs.end(),greater<pair<int, int>>());

        for (auto& p : pairs){
            float pos = p.first;
            float spd = p.second;
            float time = (target-pos)/spd;
            
            if (times.empty() || time > times.top()){
                times.push(time);
            }
        }

        return times.size();
    }
};
