#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Function to perform BFS and return number of steps
int bfs(unordered_map<int, vector<int>>& graph, int start, int end, int n) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q; // {current_person, steps_so_far}
    q.push({ start, 0 });
    visited[start] = true;

    while (!q.empty()) {
        auto [node, steps] = q.front();
        q.pop();

        if (node == end) {
            return steps;
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({ neighbor, steps + 1 });
            }
        }
    }

    // If there is no path
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    int shreya, ramya;
    cin >> shreya >> ramya;

    unordered_map<int, vector<int>> graph;

    // Initialize graph
    for (int i = 1; i <= N; ++i) {
        graph[i] = vector<int>();
    }

    // Read M relationships (edges)
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Run BFS to find shortest path
    int result = bfs(graph, ramya, shreya, N);

    cout << result << endl;
    return 0;
}