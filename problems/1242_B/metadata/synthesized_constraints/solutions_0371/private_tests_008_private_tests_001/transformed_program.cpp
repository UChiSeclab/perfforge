#include <bits/stdc++.h>
using namespace std;

int IT_MAX = 1 << 17;
int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x0f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;

void check_no_edges_invariant(long long n, long long m) {
    if (n > 10000 && m == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large graph with no weighted edges" << endl;
        abort();
    }
}

void check_not_used_invariant(size_t notUsedSize, long long n) {
    if (notUsedSize > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - many unused vertices" << endl;
        abort();
    }
}

void check_vertex_connection_invariant(long long numWeightedEdges, long long n) {
    if (numWeightedEdges < n / 100) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient vertex connections" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    long long n, m;
    cin >> n >> m;

    // Check for the first invariant after reading the input
    check_no_edges_invariant(n, m);

    vector<unordered_set<long long>> gr(n);
    for (int i = 0; i < m; ++i) {
        long long a, b;
        cin >> a >> b;
        --a;
        --b;
        gr[a].insert(b);
        gr[b].insert(a);
    }

    vector<long long> to(n);
    unordered_set<long long> ver;
    ver.reserve(1024);
    ver.max_load_factor(0.25);
    long long ans = 0;
    unordered_set<long long> q;
    q.reserve(1024);
    q.max_load_factor(0.25);
    q.insert(0);
    unordered_set<long long> not_used;
    not_used.reserve(1024);
    not_used.max_load_factor(0.25);
    for (int i = 0; i < n; ++i) {
        not_used.insert(i);
    }
    not_used.erase(0);
    
    // Check for the second invariant before entering the while loop
    check_not_used_invariant(not_used.size(), n);
    
    while (ver.size() != n) {
        long long cur_ver = *q.begin();
        q.erase(cur_ver);
        ver.insert(cur_ver);
        vector<long long> to_er;
        for (auto i : not_used) {
            if (ver.count(i) == 0) {
                if (gr[cur_ver].count(i)) {
                    to[i]++;
                }
                if (to[i] != ver.size()) {
                    to_er.push_back(i);
                    q.insert(i);
                }
            }
        }
        for (auto i : to_er) {
            not_used.erase(i);
        }
        if (q.size() == 0 && ver.size() != n) {
            long long a = *not_used.begin();
            q.insert(a);
            not_used.erase(a);
            ++ans;
        }
    }

    // Check for the third invariant after processing
    check_vertex_connection_invariant(m, n);

    cout << ans;
    return 0;
}