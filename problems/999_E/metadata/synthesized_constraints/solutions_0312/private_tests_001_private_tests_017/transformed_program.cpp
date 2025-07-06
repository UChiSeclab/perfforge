#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5010;
vector<long long> L[MAXN];
bool ok[MAXN];
bool mk[MAXN];
long long arr[MAXN];
long long contg;

// Checker functions
void check_dfs_traversal(bool condition) {
    if (condition) {
        cerr << "Warning: Frequent DFS traversals due to sparse connectivity!" << endl;
        abort();
    }
}

void check_reachability(bool condition) {
    if (condition) {
        cerr << "Warning: Inefficient reachability checks due to sparse graph!" << endl;
        abort();
    }
}

void check_array_reset(bool condition) {
    if (condition) {
        cerr << "Warning: Frequent array resets causing overhead!" << endl;
        abort();
    }
}

void check_graph_connectivity(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive time spent on recalculating graph connectivity!" << endl;
        abort();
    }
}

void precal(long long nodo) {
    mk[nodo] = true;
    contg++;
    for (auto v : L[nodo]) {
        if (!mk[v]) {
            precal(v);
        }
    }
}

void DFS(long long nodo) {
    ok[nodo] = true;
    mk[nodo] = true;
    for (auto v : L[nodo]) {
        if (!mk[v]) {
            DFS(v);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long N, M, S;
    cin >> N >> M >> S;

    // Threshold checks for connectivity and resets
    check_dfs_traversal(N > 4000 && M < N / 2);
    check_array_reset(N > 4000);

    for (long long i = 0; i < M; i++) {
        long long a, b;
        cin >> a >> b;
        L[a].push_back(b);
    }

    vector<pair<long long, long long>> vect;
    for (long long i = 1; i <= N; i++) {
        for (long long j = 0; j < MAXN; j++) mk[j] = false;
        contg = 0;
        precal(i);
        arr[i] = contg;
        vect.push_back({arr[i], i});
    }

    sort(vect.rbegin(), vect.rend());
    for (long long j = 0; j < MAXN; j++) mk[j] = false;
    DFS(S);
    long long res = 0;
    for (auto x : vect) {
        if (ok[x.second] == true) continue;
        
        // Check reachability bottleneck
        check_reachability(N > 4000);

        bool flag = true;
        for (long long i = 1; i <= N; i++) {
            flag = flag & ok[i];
        }
        if (flag) break;
        res++;

        for (long long i = 0; i < MAXN; i++) {
            mk[i] = false;
        }
        DFS(x.second);

        // Check graph connectivity recalculation bottleneck
        check_graph_connectivity(N > 4000 && res > N / 10);
    }
    cout << res << '\n';
    return 0;
}