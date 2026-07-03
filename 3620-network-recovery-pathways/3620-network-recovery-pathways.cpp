#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> in_degree(n, 0);
        for (int u = 0; u < n; ++u) {
            for (const auto& neighbor : adj[u]) {
                in_degree[neighbor.first]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo_order;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo_order.push_back(u);
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }

        auto check = [&](int target) -> bool {
            vector<long long> dp(n, k + 1);
            dp[0] = 0;

            for (int u : topo_order) {
                if (dp[u] > k) continue;
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int cost = neighbor.second;

                    if (cost < target) continue;

                    if (dp[u] + cost < dp[v]) {
                        dp[v] = dp[u] + cost;
                    }
                }
            }
            return dp[n - 1] <= k;
        };

        int low = 0, high = 1e9;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};