class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<vector<int>> solution;
            if (rowIndex == 0){
                vector<int> x;
                x.push_back(1);
                return x;
            }
            vector<int> x;
            x.push_back(1);
            solution.push_back(x);
    
            for (int i = 0; i < rowIndex; i++){
                int prev = -1;
                int curr = 0;
                vector<int> x;
                while(prev != solution[i].size()){
    
                    if (prev == -1 || curr == solution[i].size()){
                        if (prev == -1){
                            x.push_back(solution[i][curr]);
                        }
                        else if(curr == solution[i].size()){
                            x.push_back(solution[i][prev]);
                        }
                    }
                    else{
                        x.push_back(solution[i][prev] + solution[i][curr]);
                    }
                    prev++;
                    curr++;
    
                }
                solution.push_back(x);
            }
            return solution[rowIndex];
        }
    };