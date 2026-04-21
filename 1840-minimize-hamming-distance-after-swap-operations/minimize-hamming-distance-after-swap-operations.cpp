class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &it : allowedSwaps)
            unite(it[0], it[1]);

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        int ans = 0;

        for (auto &grp : groups) {
            unordered_map<int, int> freq;

            for (int idx : grp.second)
                freq[source[idx]]++;

            for (int idx : grp.second) {
                if (freq[target[idx]] > 0)
                    freq[target[idx]]--;
                else
                    ans++;
            }
        }

        return ans;
    }
};