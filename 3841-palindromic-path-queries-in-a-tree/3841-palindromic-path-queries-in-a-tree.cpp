class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        auto suneravilo = make_tuple(n, edges, s, queries);

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> tin(n), tout(n), depth(n, 0);
        int timer = 0;

        vector<pair<int, int>> st;
        st.push_back({0, -1});

        while (!st.empty()) {
            auto [u, state] = st.back();
            st.pop_back();

            if (state == -1) {
                tin[u] = ++timer;
                st.push_back({u, -2});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == up[0][u] && u != 0) continue;
                    if (v == 0 && u == 0) continue;

                    up[0][v] = u;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, -1});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int val) {
            while (idx <= n + 1) {
                bit[idx] ^= val;
                idx += idx & -idx;
            }
        };

        auto rangeUpdate = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        auto get = [&](int idx) {
            int res = 0;
            while (idx > 0) {
                res ^= bit[idx];
                idx -= idx & -idx;
            }
            return res;
        };

        auto mask = [&](char c) {
            return 1 << (c - 'a');
        };

        for (int i = 0; i < n; i++) {
            rangeUpdate(tin[i], tout[i], mask(s[i]));
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[j][u];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);
                rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int ancestor = lca(u, v);
                int pathMask = get(tin[u]) ^ get(tin[v]) ^ mask(s[ancestor]);

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna