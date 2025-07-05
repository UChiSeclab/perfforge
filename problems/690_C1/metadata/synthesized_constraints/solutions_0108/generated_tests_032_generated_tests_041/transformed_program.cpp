#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> v;

void check_sparse_connectivity(int n, int m) {
    if (m < n / 4) { // Assuming a threshold where m is significantly smaller than n
        cerr << "Warning: Sparse connectivity invariant triggered - low number of connectors!" << endl;
        abort();
    }
}

void check_large_graph(int n) {
    if (n > 900) { // Close to the maximum n value
        cerr << "Warning: Large graph invariant triggered - too many brains!" << endl;
        abort();
    }
}

void check_disconnected_components(const vector<bool>& used) {
    if (find(used.begin(), used.end(), false) != used.end()) {
        cerr << "Warning: Disconnected component invariant triggered - unreachable brains!" << endl;
        abort();
    }
}

void bfs(int start) {
    int n = v.size();
    queue<int> q;
    q.push(start);
    vector<bool> used(n);
    used[start] = true;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (v[tmp][i]) {
                if (used[i])
                    count++;
                else
                    q.push(i);
                used[i] = true;
            }
        }
        if (count > 1) {
            cout << "no";
            return;
        }
    }
    // Check for disconnected components after BFS
    check_disconnected_components(used);

    if (find(used.begin(), used.end(), false) != used.end())
        cout << "no";
    else
        cout << "yes";
}

int main() {
    int n, m;
    cin >> n >> m;

    // Check for sparse connectivity and large graph before heavy operations
    check_sparse_connectivity(n, m);
    check_large_graph(n);

    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(n);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x - 1][y - 1] = v[y - 1][x - 1] = true;
    }
    bfs(0);
}