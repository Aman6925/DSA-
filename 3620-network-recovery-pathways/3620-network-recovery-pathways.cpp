class Solution {
public:
    typedef long long ll;
    typedef pair<ll, int> p;

    bool check(int mid, int n, ll k,
               unordered_map<int, vector<vector<int>>> &adj) {

        vector<ll> dist(n, LLONG_MAX);
        priority_queue<p, vector<p>, greater<p>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            if (d > k)
                break;

            if (node == n - 1)
                return true;

            for (auto &edge : adj[node]) {
                int ngbr = edge[0];
                int cost = edge[1];

                if (cost < mid)
                    continue;

                if (d + cost < dist[ngbr]) {
                    dist[ngbr] = d + cost;
                    pq.push({dist[ngbr], ngbr});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        if (!online[0] || !online[n - 1])
            return -1;

        unordered_map<int, vector<vector<int>>> adj;

        int l = INT_MAX;
        int r = 0;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if (!online[u] || !online[v])
                continue;

            adj[u].push_back({v, cost});

            l = min(l, cost);
            r = max(r, cost);
        }

        if (l == INT_MAX)
            return -1;

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, n, k, adj)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};