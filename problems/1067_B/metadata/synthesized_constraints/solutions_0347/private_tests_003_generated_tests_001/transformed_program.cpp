#include <bits/stdc++.h>
using namespace std;

const long long MAXN = 2e5 + 10;
vector<long long> adj[MAXN];
long long n, k, v, u, mark[MAXN], cnt[MAXN];

void check_vertex_degree_condition(const vector<long long>& cnt, long long n) {
    int lowDegreeCount = 0;
    for (long long i = 1; i <= n; i++) {
        if (cnt[i] < 3 && cnt[i] != 0) {
            lowDegreeCount++;
        }
    }
    if (lowDegreeCount > n / 10) { // Arbitrarily chosen threshold
        cerr << "Warning: Performance bottleneck - too many vertices with degree < 3" << endl;
        abort();
    }
}

void check_recursive_processing_condition(long long recursionDepth, long long threshold) {
    if (recursionDepth > threshold) {
        cerr << "Warning: Performance bottleneck - excessive recursion depth" << endl;
        abort();
    }
}

void check_graph_structure_complexity(const vector<long long>& adjSizes, long long n) {
    int complexStructureCount = 0;
    for (long long size : adjSizes) {
        if (size > 3) {
            complexStructureCount++;
        }
    }
    if (complexStructureCount > n / 20) { // Arbitrarily chosen threshold for complex structures
        cerr << "Warning: Performance bottleneck - complex graph structure" << endl;
        abort();
    }
}

void solve(vector<long long> vec, long long recursionDepth = 0) {
    if (vec.size() == 0) return;
    if (k == 0 && vec.size() != 1) {
        cout << "No" << '\n';
        exit(0);
    }
    set<long long> st;
    k--;
    for (long long i : vec) mark[i] = 1;
    for (long long v : vec) {
        for (long long u : adj[v]) {
            if (!mark[u]) {
                cnt[u]++;
                st.insert(u);
            }
        }
    }
    check_recursive_processing_condition(++recursionDepth, 100); // Example threshold
    solve(vector<long long>(st.begin(), st.end()), recursionDepth);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k;
    for (long long i = 1; i < n; i++) {
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<long long> vec;
    for (long long i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            vec.push_back(i);
        }
    }
    
    check_graph_structure_complexity(vector<long long>(adj, adj + n + 1), n);

    solve(vec);
    
    check_vertex_degree_condition(vector<long long>(cnt, cnt + MAXN), n);

    for (long long i = 1; i <= n; i++) {
        if (cnt[i] < 3 && cnt[i] != 0) return cout << "No" << '\n', 0;
    }
    if (accumulate(cnt, cnt + MAXN, 0) != n - 1) return cout << "No" << '\n', 0;
    if (k != -1) return cout << "No" << '\n', 0;
    cout << "Yes" << '\n';
    return 0;
}