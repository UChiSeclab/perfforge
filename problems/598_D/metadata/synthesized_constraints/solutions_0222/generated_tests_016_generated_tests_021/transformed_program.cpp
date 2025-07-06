#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int belong[1005][1005];
int n, m, k;
char g[1005][1005];
int cnt;
int ans[2000000];

// Check for large connected components
void check_large_component_invariant(int componentSize, int threshold = 500) {
    if (componentSize > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - large connected component detected!" << endl;
        abort();
    }
}

// Check for frequent calculations in calc function
void check_frequent_calc_invariant(int calcCount, int threshold = 1000) {
    if (calcCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent calculations detected!" << endl;
        abort();
    }
}

// Check for high density of starting positions
void check_starting_positions_invariant(int k, int componentCount) {
    if ((k > 0.8 * n * m) && (k > componentCount)) {
        cerr << "Warning: Performance bottleneck condition triggered - high density of starting positions!" << endl;
        abort();
    }
}

void dfs(int x, int y) {
    belong[x][y] = cnt;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny] == '*' ||
            belong[nx][ny])
            continue;
        dfs(nx, ny);
    }
}

int calc(int x, int y) {
    if (!belong[x][y]) return 0;
    int tmp = 0;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i], ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || belong[nx][ny]) continue;
        tmp++;
    }
    return tmp;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> g[i][j];
    }

    int componentCount = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i][j] != '*' && !belong[i][j]) {
                ++cnt;
                dfs(i, j);

                // Check for large connected component size
                check_large_component_invariant(cnt);
                componentCount++;
            }
        }
    }

    int calcCount = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[belong[i][j]] += calc(i, j);
            calcCount++;
        }
    }

    // Check for frequent calculations
    check_frequent_calc_invariant(calcCount);

    // Check for high density of starting positions
    check_starting_positions_invariant(k, componentCount);

    int x, y;
    while (k--) {
        cin >> x >> y;
        cout << ans[belong[x][y]] << endl;
    }
    return 0;
}