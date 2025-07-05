#include <bits/stdc++.h>
using namespace std;

int a, b;
map<int, bool> vis;

// Checker functions
void check_queue_utilization_invariant(int n, int m, int queueSize) {
    if (n < m && queueSize > 1000) { // Arbitrary threshold for excessive queue size
        cerr << "Warning: Performance bottleneck condition triggered - High Queue Utilization!" << endl;
        abort();
    }
}

void check_redundant_state_invariant(int n, int m, int decrementCount) {
    if (n < m && decrementCount > 5000) { // Arbitrary threshold for excessive decrements
        cerr << "Warning: Performance bottleneck condition triggered - Redundant State Exploration!" << endl;
        abort();
    }
}

void check_inefficient_path_search_invariant(int n, int m, int iterationCount) {
    if (n < m && iterationCount > 10000) { // Arbitrary threshold for excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - Inefficient Path Search!" << endl;
        abort();
    }
}

int bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(a, 0));
    int decrementCount = 0; // Track number of decrements
    int iterationCount = 0; // Track number of BFS iterations

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        vis[cur.first] = 1;

        iterationCount++;
        check_inefficient_path_search_invariant(a, b, iterationCount);

        if (cur.first == b) {
            return cur.second;
        }

        if (!vis[cur.first * 2] && cur.first <= b) {
            q.push(make_pair(cur.first * 2, cur.second + 1));
        }

        if (!vis[cur.first - 1]) {
            q.push(make_pair(cur.first - 1, cur.second + 1));
            decrementCount++;
            check_redundant_state_invariant(a, b, decrementCount);
        }

        check_queue_utilization_invariant(a, b, q.size());
    }
}

int main() {
    cin >> a >> b;
    cout << bfs() << endl;
    return 0;
}