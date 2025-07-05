#include <bits/stdc++.h>
using namespace std;

int col[1000][1000] = {{0}};
int n1 = 0;
int n2 = 0;
int N, M;

void check_matrix_size_invariant(int n, int m) {
    if (n * m > 500000) {  // Threshold for large matrix size
        cerr << "Warning: Performance bottleneck condition triggered - large matrix size!" << endl;
        abort();
    }
}

void check_queue_utilization_invariant(int queueSize) {
    if (queueSize > 10000) {  // Arbitrary threshold for queue size
        cerr << "Warning: Performance bottleneck condition triggered - excessive queue utilization!" << endl;
        abort();
    }
}

void check_conflict_checks_invariant(int n, int m, int colHits) {
    if (colHits > 10 * n * m) {  // Threshold for excessive checks
        cerr << "Warning: Performance bottleneck condition triggered - excessive conflict checks!" << endl;
        abort();
    }
}

void go(queue<pair<int, int>> &q, int u, int v, int x, int y, int &colHits) {
    colHits++;
    if (x >= 0 && y >= 0 && x < N && y < M && col[x][y] == 0) {
        q.push(make_pair(x, y));
        col[x][y] = 3 - col[u][v];
        if (col[x][y] == 1)
            ++n1;
        else
            ++n2;
    }
}

int main() {
    cin >> N >> M;
    check_matrix_size_invariant(N, M);  // Check for large matrix size

    int x, y;
    int ans = 0;
    int colHits = 0;  // Track the number of times go is called

    for (int _n = N, ii = 0; ii < _n; ++ii)
        for (int _n = M, jj = 0; jj < _n; ++jj) {
            if (col[ii][jj]) continue;
            col[ii][jj] = 1;
            n1 = 1;
            n2 = 0;
            queue<pair<int, int>> q;
            q.push(make_pair(ii, jj));

            while (!q.empty()) {
                check_queue_utilization_invariant(q.size());  // Check excessive queue utilization

                int u = q.front().first;
                int v = q.front().second;
                q.pop();
                
                for (int x = (max(u - 2, 0)), _b = (min(u + 2, N - 1)); x <= _b; ++x)
                    for (int y = (max(v - 2, 0)), _b = (min(v + 2, M - 1)); y <= _b; ++y)
                        if ((x - u) * (x - u) + (y - v) * (y - v) == 5)
                            go(q, u, v, x, y, colHits);
            }
            ans += max(n1, n2);
        }
    check_conflict_checks_invariant(N, M, colHits);  // Check excessive conflict checks
    cout << ans << endl;
}