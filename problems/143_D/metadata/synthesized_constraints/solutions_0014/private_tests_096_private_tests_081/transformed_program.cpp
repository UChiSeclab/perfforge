#include <bits/stdc++.h>
using namespace std;

int n, m;

bool isvalid(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

// Invariant checker functions
void check_large_grid_invariant(int n, int m) {
    if (n > 900 && m > 900) {
        cerr << "Warning: Performance bottleneck condition triggered - large grid size." << endl;
        abort();
    }
}

void check_cell_visit_invariant(int n, int m) {
    if (n * m > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered - high cell visit frequency." << endl;
        abort();
    }
}

void check_boundary_checks_invariant(int boundary_checks, int threshold) {
    if (boundary_checks > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent boundary checks." << endl;
        abort();
    }
}

void check_queue_operations_invariant(int operations) {
    if (operations > 5000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive queue operations." << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;

    // Insert checks after reading input
    check_large_grid_invariant(n, m);
    check_cell_visit_invariant(n, m);

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<int>> col(n, vector<int>(m, -1));
    int ans = 0;
    int boundary_checks = 0;  // To keep track of boundary checks
    int queue_operations = 0; // To keep track of queue operations

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;
                col[i][j] = 0;
                int co = 0, cz = 1;

                while (!q.empty()) {
                    pair<int, int> temp = q.front();
                    q.pop();
                    int x = temp.first;
                    int y = temp.second;

                    for (int k = 0; k < 8; k++) {
                        int nx = dx[k] + x;
                        int ny = dy[k] + y;

                        boundary_checks++; // Increment boundary check count
                        if (isvalid(nx, ny) && !vis[nx][ny]) {
                            vis[nx][ny] = true;
                            q.push({nx, ny});
                            queue_operations++; // Increment queue operations
                            col[nx][ny] = col[x][y] ^ 1;
                            if (col[nx][ny])
                                co++;
                            else
                                cz++;
                        }
                    }
                }
                ans += max(co, cz);
            }
        }
    }

    // Insert checks after major computation
    check_boundary_checks_invariant(boundary_checks, 4000000);
    check_queue_operations_invariant(queue_operations);

    cout << ans << endl;
}