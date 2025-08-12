class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string i : tokens){
            if (i != "+" && i != "-" && i != "*" && i != "/"){
                s.push(stoi(i));
            }
            else{
                int last = s.top(); s.pop();
                int last_2 = s.top(); s.pop();
                
                if(i == "+") { s.push(last_2 + last); }
                else if(i == "-") { s.push(last_2 - last); }
                else if(i == "/") { s.push(last_2 / last); }
                else if(i == "*") { s.push(last_2 * last); }
            }
        }
        return s.top();
    }
};
c