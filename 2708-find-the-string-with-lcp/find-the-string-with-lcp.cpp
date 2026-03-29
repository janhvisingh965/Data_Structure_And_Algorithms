class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[a] = b;
    }
};

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: Basic checks
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }
        
        // Step 2: DSU for equal characters
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > 0) {
                    dsu.unite(i, j);
                }
            }
        }
        
        // Step 3: Assign characters
        unordered_map<int, char> mp;
        char ch = 'a';
        string res(n, '?');
        
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            if (!mp.count(root)) {
                if (ch > 'z') return "";
                mp[root] = ch++;
            }
            res[i] = mp[root];
        }
        
        // Step 4: Validate LCP
        vector<vector<int>> check(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (res[i] == res[j]) {
                    if (i + 1 < n && j + 1 < n)
                        check[i][j] = 1 + check[i + 1][j + 1];
                    else
                        check[i][j] = 1;
                }
            }
        }
        
        if (check != lcp) return "";
        
        return res;
    }
};