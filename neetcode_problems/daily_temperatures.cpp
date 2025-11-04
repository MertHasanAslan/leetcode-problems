class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> s;
        vector<int> result(temperatures.size());


        for(int i = 0; i < temperatures.size(); i++){

            while(s.empty() == false && temperatures[i] > s.top().first){
                result[s.top().second] = i-s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return result;
    }
};
