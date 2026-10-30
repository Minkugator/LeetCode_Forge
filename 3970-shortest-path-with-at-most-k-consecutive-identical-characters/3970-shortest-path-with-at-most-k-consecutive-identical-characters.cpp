class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        // {distance, node, consecutive_count}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if (d > dist[node][cnt]) {
                continue;
            }

            if (node == n - 1) {
                return d;
            }

            for (auto& [next, weight] : adj[node]) {

                int newCnt;

                if (labels[node] == labels[next]) {
                    newCnt = cnt + 1;
                } 
                else {
                    newCnt = 1;
                }

                if (newCnt > k) {
                    continue;
                }

                int newDist = d + weight;

                if (newDist < dist[next][newCnt]) {
                    dist[next][newCnt] = newDist;
                    pq.push({newDist, next, newCnt});
                }
            }
        }

        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna