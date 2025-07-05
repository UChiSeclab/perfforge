#include <bits/stdc++.h>
using namespace std;

// Function to check recursion depth
void check_recursion_depth(int currentDepth, int maxAllowedDepth) {
    if (currentDepth > maxAllowedDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

// Function to check the degree processing
void check_degree_processing(int degreeOneCount, int totalVertices) {
    if (degreeOneCount > totalVertices / 2) { // Arbitrary threshold: more than half are leaves
        cerr << "Warning: Performance bottleneck condition triggered - too many degree-1 vertices!" << endl;
        abort();
    }
}

// Function to check adjacency operations
void check_adjacency_operations(int adjacencyOperations, int threshold) {
    if (adjacencyOperations > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive adjacency list operations!" << endl;
        abort();
    }
}

bool is_khog(vector<int> vertices, vector<vector<int>> edges, int K, int currentDepth) {
    check_recursion_depth(currentDepth, 100);  // Assuming 100 as a reasonable depth threshold

    map<int, int> deg;
    vector<int> rem;
    int degreeOneCount = 0;
    int adjacencyOperations = 0;

    for (auto &v : vertices) {
        if (edges[v].size() == 1) {
            int u = edges[v][0];
            deg[u]++;
            degreeOneCount++;
        } else {
            rem.push_back(v);
        }
    }

    check_degree_processing(degreeOneCount, vertices.size());

    for (auto &v : deg) {
        if (v.second < 3) {
            return false;
        }
    }

    if (K == 1) {
        return (deg.size() == 1);
    }

    for (auto &v : deg) {
        vector<int> &adj = edges[v.first];
        bool f = false;
        while (adj.size() > 1) {
            int u = adj.back();
            if (edges[u].size() > 1) {
                if (f) {
                    return false;
                }
                f = true;
                swap(adj[adj.size() - 1], adj[0]);
            } else {
                adj.pop_back();
            }
            adjacencyOperations++;
        }
    }

    check_adjacency_operations(adjacencyOperations, 10 * vertices.size());

    return is_khog(rem, edges, K - 1, currentDepth + 1);
}

int main() {
    int N, K;
    cin >> N >> K;
    int ms = 4;
    for (int i = 2; i <= K; ++i) {
        ms *= 3;
        if (ms > N) {
            cout << "No" << endl;
            return 0;
        }
    }
    vector<int> vertices;
    for (int i = 1; i <= N; ++i) {
        vertices.push_back(i);
    }
    vector<vector<int>> E(N + 1);
    for (int i = 1; i < N; ++i) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    if (is_khog(vertices, E, K, 0)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}