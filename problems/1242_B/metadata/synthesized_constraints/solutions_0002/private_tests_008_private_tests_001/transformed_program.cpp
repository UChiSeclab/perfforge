#include <bits/stdc++.h>
using namespace std;

// Checker for graph size and connectivity
void check_graph_size_connectivity(int n, int m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Potential performance bottleneck - large, sparse graph (n is large and m is 0)" << endl;
        abort();
    }
}

// Checker for traversal operations
void check_traversal_operations(int n, int m) {
    if (n > 10000 && m < n / 10) {
        cerr << "Warning: Traversal performance bottleneck - large graph with very few edges" << endl;
        abort();
    }
}

// Checker for queue operations
void check_queue_operations(int n, int size) {
    if (n > 10000 && size > n * 0.5) {
        cerr << "Warning: Queue operation bottleneck - excessive operations in large sparse graph" << endl;
        abort();
    }
}

map<pair<int, int>, int> edges;
set<int> vertex;
vector<int> comp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, u, v, cnt;
    cin >> n >> m;
    
    // Insert checkers after reading input
    check_graph_size_connectivity(n, m);
    check_traversal_operations(n, m);
    
    for (int i = 1; i <= n; i++) {
        vertex.insert(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        edges[{u, v}] = 1;
        edges[{v, u}] = 1; 
    }
    
    while (!vertex.empty()) {
        u = *vertex.begin();
        cnt = 1;
        vertex.erase(vertex.begin());
        queue<int> q;
        q.push(u);
        while (!q.empty()) {
            v = q.front();
            q.pop();
            auto itr = vertex.begin();
            while (itr != vertex.end()) {
                bool found = false;
                if (!edges[{*itr, v}]) {
                    found = true;
                }
                if (found) {
                    q.push(*itr);
                    cnt++;
                    itr = vertex.erase(itr);
                } else {
                    itr++;
                }
            }
            // Check inside the traversal to monitor queue size
            check_queue_operations(n, q.size());
        }
        comp.push_back(cnt);
    }
    
    cout << comp.size() - 1 << endl;
}