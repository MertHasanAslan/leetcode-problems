class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed;
        stack<float> s;

        for (int i = 0; i < position.size(); i++){
            pos_speed.push_back({position[i], speed[i]});
        }
        
        sort(pos_speed.rbegin(), pos_speed.rend());

        float step = (float)(target - pos_speed[0].first) / pos_speed[0].second;
        s.push(step);

        for (int i = 1; i < pos_speed.size(); i++){
            float step = (float)(target-pos_speed[i].first) / pos_speed[i].second;

            if (step > s.top()){
                s.push(step);
            }
        }        
        return s.size();
    }
};
