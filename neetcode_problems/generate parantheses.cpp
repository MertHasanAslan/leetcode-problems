class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs("", result, n);
        return result;
    }

    void dfs(string str, vector<string>& result, int n){
        if (str.size() == n*2){
            if (isValid(str)){
                result.push_back(str);
                return;
            }
            else{
                return;
            }
        }
        
        dfs(str + '(', result, n);
        dfs(str + ')', result, n);
    }

    bool isValid(string str){
        int open = 0;
        for (char ch : str){
            if (ch == '(') { open++; }
            else { open--; }

            if (open < 0) { return false; }
        }

        return open == 0;
    }
};
