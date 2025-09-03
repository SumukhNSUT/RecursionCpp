#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

struct Seed {
    int user, cost;
    double ratio;
    bool operator<(const Seed& other) const {
        return ratio > other.ratio; // For descending sort
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int k;
    cin >> k;
    vector<Seed> seeds(k);
    for (int i = 0; i < k; i++) {
        int user, cost;
        cin >> user >> cost;
        seeds[i].user = user;
        seeds[i].cost = cost;
    }
    vector<int> values(n + 1);
    for (int i = 1; i <= n; i++) cin >> values[i];
    int budget, depth;
    cin >> budget >> depth;

    // Compute ratios for greedy
    for (int i = 0; i < k; i++) {
        seeds[i].ratio = (double)values[seeds[i].user] / seeds[i].cost;
    }
    sort(seeds.begin(), seeds.end());

    vector<int> chosen;
    int total_cost = 0;
    set<int> reached;
    for (auto& s : seeds) {
        if (total_cost + s.cost > budget) continue;
        // Spread influence from this user up to the given depth
        queue<pair<int, int>> q;
        set<int> vis = reached;
        q.push({ s.user, 0 });
        vis.insert(s.user);
        while (!q.empty()) {
            auto [u, d] = q.front(); q.pop();
            if (d >= depth) continue;
            for (int v : graph[u]) {
                if (!vis.count(v)) {
                    vis.insert(v);
                    q.push({ v, d + 1 });
                }
            }
        }
        if (vis.size() > reached.size()) { // Only add if adds new reach
            chosen.push_back(s.user);
            total_cost += s.cost;
            reached = vis;
        }
    }
    int total_value = 0;
    for (int u : reached) total_value += values[u];

    // Output in expected format
    for (int i = 0; i < chosen.size(); ++i) {
        if (i) cout << " ";
        cout << chosen[i];
    }
    cout << endl;
    cout << total_value << endl;
    cout << total_cost << endl;
    return 0;
}
    