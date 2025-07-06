#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e18;
int n, m;
int edges[22][2];
bool used[6][6];
int arr[7];

void check_large_edges(int n, int m) {
    if (m > (n * (n - 1)) / 3) { // arbitrary high density threshold
        cerr << "Warning: Performance bottleneck condition triggered - large number of edges!" << endl;
        abort();
    }
}

void check_exhaustive_search() {
    if (true) { // The check is primarily informational, to highlight the exhaustive search approach
        cerr << "Warning: Performance bottleneck condition triggered - inefficient exhaustive search!" << endl;
        abort();
    }
}

void check_iteration_complexity(int n, int m) {
    if (m > 6 && n > 5) { // arbitrary condition to denote potential high complexity
        cerr << "Warning: Performance bottleneck condition triggered - high iteration complexity!" << endl;
        abort();
    }
}

void init() {}

void input() {
    cin >> n >> m;
    check_large_edges(n, m); // Check for large number of edges
    check_iteration_complexity(n, m); // Check high iteration complexity
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--;
        edges[i][1]--;
    }
}

int check() {
    int now = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            used[i][j] = false;
        }
    }
    for (int i = 0; i < m; i++) {
        int v = edges[i][0], u = edges[i][1];
        if (!used[arr[v]][arr[u]]) {
            now++;
            used[arr[v]][arr[u]] = true;
            used[arr[u]][arr[v]] = true;
        }
    }
    return now;
}

void solve() {
    check_exhaustive_search(); // Check for inefficient exhaustive search
    int ans = 0;
    for (arr[0] = 1; arr[0] < 7; arr[0]++) {
        for (arr[1] = 1; arr[1] < 7; arr[1]++) {
            for (arr[2] = 1; arr[2] < 7; arr[2]++) {
                for (arr[3] = 1; arr[3] < 7; arr[3]++) {
                    for (arr[4] = 1; arr[4] < 7; arr[4]++) {
                        for (arr[5] = 1; arr[5] < 7; arr[5]++) {
                            for (arr[6] = 1; arr[6] < 7; arr[6]++) {
                                ans = max(ans, check());
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

void output() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int number_of_testcases = 1;
    while (number_of_testcases--) {
        init();
        input();
        solve();
        output();
    }
    return 0;
}