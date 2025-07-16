class Solution {
public:
    bool isAnagram(string first, string second) {
        if (first.size() != second.size()) { return false; }
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i = 0; i < first.size(); i++){
            map1[first[i]]++;
            map2[second[i]]++;
        }

        for (int i = 0; i < first.size(); i++){
            if (map1[first[i]] != map2[first[i]]) {return false;}
        }
        return true;
    }
};
