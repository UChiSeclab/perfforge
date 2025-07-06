#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> E[101010];
int D[101010];
vector<int> Ds[101010];

// Function prototypes for the invariant checks
void check_bfs_exhaustive_traversal(int N, const vector<int>& degrees);
void check_excessive_iteration(int K, int N);
void check_vertex_degree_mismatch(const vector<int>& degrees);
void check_k_multihedgehog_constraint(int K, int N);

void solve() {
    int i, j, k, l, r, x, y;
    string s;
    cin >> N >> K;
    
    vector<int> degrees(N, 0);
    
    for (i = 0; i < (N - 1); i++) {
        cin >> x >> y;
        E[x - 1].push_back(y - 1);
        E[y - 1].push_back(x - 1);
        degrees[x - 1]++;
        degrees[y - 1]++;
    }

    // Insert checks based on performance-characterizing invariants
    check_bfs_exhaustive_traversal(N, degrees);
    check_excessive_iteration(K, N);
    check_vertex_degree_mismatch(degrees);
    check_k_multihedgehog_constraint(K, N);

    if (N == 1) return (void)printf("No\n");

    queue<int> Q;
    for (i = 0; i < (N); i++) {
        D[i] = 101010;
        if (E[i].size() == 1) {
            D[i] = 0;
            Q.push(i);
        }
    }
    while (Q.size()) {
        x = Q.front();
        Q.pop();
        Ds[D[x]].push_back(x);
        for (auto& e : E[x])
            if (D[e] > D[x] + 1) {
                D[e] = D[x] + 1;
                Q.push(e);
            }
    }
    if (K > 100000 || Ds[K].size() != 1) return (void)printf("No\n");
    x = 0;
    for (i = K + 1; i <= 101000; i++) x += Ds[i].size();
    if (x) return (void)printf("No\n");
    for (i = 0; i < (N); i++)
        if (D[i]) {
            int num = 0;
            for (auto& e : E[i]) {
                if (D[e] == D[i] + 1)
                    continue;
                else if (D[e] == D[i] - 1)
                    num++;
                else
                    return (void)printf("No\n");
            }
            if (num < 3) return (void)printf("No\n");
        }
    (void)printf("Yes\n");
}

int main(int argc, char** argv) {
    string s;
    int i;
    if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
    for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
    for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
    cout.tie(0);
    solve();
    return 0;
}

// Function definitions for the invariant checks
void check_bfs_exhaustive_traversal(int N, const vector<int>& degrees) {
    int leaf_count = 0;
    for (int degree : degrees) {
        if (degree == 1) {
            leaf_count++;
        }
    }
    if (N > 10 && leaf_count > N / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - exhaustive BFS traversal due to many leaf nodes!" << endl;
        abort();
    }
}

void check_excessive_iteration(int K, int N) {
    if (K < N / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iteration due to small K!" << endl;
        abort();
    }
}

void check_vertex_degree_mismatch(const vector<int>& degrees) {
    int inconsistencies = 0;
    for (int degree : degrees) {
        if (degree != 1 && degree != 3) {
            inconsistencies++;
        }
    }
    if (inconsistencies > degrees.size() / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - vertex degree mismatches detected!" << endl;
        abort();
    }
}

void check_k_multihedgehog_constraint(int K, int N) {
    if (K > N / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive K relative to N!" << endl;
        abort();
    }
}