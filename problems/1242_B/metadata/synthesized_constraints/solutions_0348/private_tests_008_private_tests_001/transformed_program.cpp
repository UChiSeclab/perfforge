#include <bits/stdc++.h>
using namespace std;

template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
    os << "[ ";
    for (auto v : V) os << v << ", ";
    return os << "]";
}

template <class T>
ostream& operator<<(ostream& os, set<T> S) {
    os << "{ ";
    for (auto s : S) os << s << ", ";
    return os << "}";
}

template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
    return os << "(" << P.first << "," << P.second << ")";
}

template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
    os << "{ ";
    for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
    return os << "}";
}

// Checker for performance bottleneck condition
void check_slowdown_when_large_n_and_small_m(int n, int m) {
    // If the number of vertices n is large and the number of edges m is small or zero
    if (n >= 80000 && m <= 1000) { // These thresholds are chosen to be broad but indicative of potential slowdown
        cerr << "Warning: Performance bottleneck condition triggered - large n with small m!" << endl;
        abort();
    }
}

int n, m;
map<pair<int, int>, bool> edge;
set<int> node;
vector<bool> visited(200005, false);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vector<int> temp;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = true;
        temp.clear();
        for (int u : node) {
            if (!edge[{u, v}] && !visited[u]) {
                temp.push_back(u);
            }
        }
        for (int u : temp) {
            node.erase(u);
            q.push(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    // Insert performance check after reading inputs and before processing
    check_slowdown_when_large_n_and_small_m(n, m);

    for (int i = 0; i < n; i++) {
        node.insert(i);
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        edge[{x, y}] = 1;
        edge[{y, x}] = 1;
    }
    int cnt = 0;
    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            node.erase(start);
            bfs(start);
            cnt++;
        }
        if (node.empty()) break;
    }
    cout << cnt - 1 << endl;
}