class Solution {
public:
    unordered_set<char> charset;
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;

        for (int right = 0; right < s.size(); right++){
            while (charset.find(s[right]) != charset.end()){
                charset.erase(s[left]);
                left++;
            }

            charset.insert(s[right]);

            res = max(res, right - left + 1);
        }

        return res;

    }
};
