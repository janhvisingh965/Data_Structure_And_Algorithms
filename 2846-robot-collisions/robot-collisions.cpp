class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(robots.begin(), robots.end()); // sort by position
        
        stack<int> st; // indices in robots
        
        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R') {
                st.push(i);
            } else {
                while(!st.empty() && get<1>(robots[i]) > 0) {
                    int j = st.top();
                    
                    if(get<1>(robots[j]) < get<1>(robots[i])) {
                        // stack robot dies
                        get<1>(robots[i]) -= 1;
                        get<1>(robots[j]) = 0;
                        st.pop();
                    }
                    else if(get<1>(robots[j]) > get<1>(robots[i])) {
                        // current robot dies
                        get<1>(robots[j]) -= 1;
                        get<1>(robots[i]) = 0;
                        break;
                    }
                    else {
                        // both die
                        get<1>(robots[j]) = 0;
                        get<1>(robots[i]) = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        
        vector<int> ans(n, 0);
        
        for(auto &[pos, health, dir, idx] : robots) {
            if(health > 0) {
                ans[idx] = health;
            }
        }
        
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(ans[i] > 0) res.push_back(ans[i]);
        }
        
        return res;
    }
};