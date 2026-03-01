class Solution {
public:
    string minWindow(string s, string t) {
        string result = "";
        unordered_map<char, int> restriction;
        unordered_map<char, int> counts;
        int result_start = 0;
        int result_end = s.size();
        int l = 0;
        int min_len = s.size();
        bool checker = true;
        
        for (char& c : t){
            restriction[c]++;
        }

        for (int r = 0; r < s.size(); r++){
            counts[s[r]]++;
            checker = true;

            while (true){
                for (char& c : t){
                    if (restriction[c] > counts[c]){
                        checker = false;
                        break;
                    }
                }

                if (checker == false) {
                    break;
                }

                if ((r - l) < (min_len)){
                    result_start = l;
                    result_end = r;
                    min_len = result_end - result_start;
                }
                counts[s[l]]--;
                l++;
            }
        }

        if (result_end - result_start == s.size()) {
            return "";
        }

        for (int i = result_start; i <= result_end; i++){
            result = result + s[i];
        }

        return result;

    }
};
