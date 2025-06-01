class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        vector<int> group(n+1, 0);
        queue<int> q;

        for(int i = 0; i < dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }


        for(int i = 0; i < n; i++){
            if(group[i] != 0) { continue; }

            group[i] = 1;
            for(q.push(i); q.empty() != true; q.pop()){
                int vertex = q.front();
                for(int neighbor : adj[vertex]){
                    if (group[neighbor] == 0){
                        group[neighbor] = -group[vertex];
                        q.push(neighbor);
                    }
                    else{
                        if(group[neighbor] == group[vertex]) { return false; }
                    }
                }
            }
        }
        return true;
    }
};