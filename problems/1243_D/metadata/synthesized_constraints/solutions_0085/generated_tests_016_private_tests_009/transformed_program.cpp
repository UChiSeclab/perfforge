#include <bits/stdc++.h>
using namespace std;

// Checker function for large vertex count
void check_large_vertex_count(bool condition) {
    if (condition) {
        cerr << "Warning: Large vertex count may cause performance issues!" << endl;
        abort();
    }
}

// Checker function for sparse graph with BFS
void check_sparse_graph_with_bfs(bool condition) {
    if (condition) {
        cerr << "Warning: Sparse graph with BFS may lead to increased computation time!" << endl;
        abort();
    }
}

// Checker function for frequent set operations and sorting
void check_set_operations_sorting(bool condition) {
    if (condition) {
        cerr << "Warning: Frequent set operations and sorting may degrade performance!" << endl;
        abort();
    }
}

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vpii = vector<pii>;
using ld = long double;
using vs = vector<string>;
mt19937_64 rnd((unsigned long)chrono::high_resolution_clock::now()
                   .time_since_epoch()
                   .count());

const int MAXN = 1e5 + 9;
vvi gg;
int n, m;
set<int> st;
bool used[MAXN];

void bfs(int v) {
    queue<int> qq;
    used[v] = 1;
    qq.push(v);
    while (!qq.empty()) {
        int v = qq.front();
        qq.pop();
        int pos = 0;
        st.erase(v);
        sort((gg[v]).begin(), (gg[v]).end());
        set<int> tmp;
        for (int x : st) {
            while (pos < (int)(gg[v]).size() && gg[v][pos] < x) {
                pos++;
            }
            if (pos == (int)(gg[v]).size() || gg[v][pos] > x) {
                assert(used[x] == 0);
                used[x] = 1;
                qq.push(x);
                tmp.insert(x);
            }
        }
        for (auto x : tmp) {
            st.erase(x);
        }
    }
}

void solve() {
    cin >> n >> m;

    // Integrate the checkers
    check_large_vertex_count(n > 10000); // Adjust threshold as necessary
    check_sparse_graph_with_bfs(n > 1000 && m < n / 10); // Example condition
    check_set_operations_sorting(n > 5000); // Example condition

    gg.resize(n);
    for (int i = 0; i < n; i++) st.insert(i);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        gg[a].push_back(b);
        gg[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(12);
    cerr.setf(ios::fixed | ios::showpoint);
    cerr.precision(4);
    
    solve();
    return 0;
}