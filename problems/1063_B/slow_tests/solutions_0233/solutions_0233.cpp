#include <bits/stdc++.h>
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
using namespace std;
char a[2001][2001];
vector<pair<long long, long long> > dp[2001];
int x, y, r, c, n, m;
bool visited[2001][2001];
void bfs(int r, int c) {
  deque<pair<long long, long long> > q;
  q.push_front({r, c});
  while (!q.empty()) {
    pair<long long, long long> xx = q[0];
    q.pop_front();
    r = xx.first;
    c = xx.second;
    if (c - 1 >= 0 && a[r][c - 1] == '.' && !visited[r][c - 1] &&
        dp[r][c].first + 1 <= x) {
      dp[r][c - 1].first = dp[r][c].first + 1;
      dp[r][c - 1].second = dp[r][c].second;
      visited[r][c - 1] = true;
      q.push_back({r, c - 1});
    }
    if (c + 1 < m && a[r][c + 1] == '.' && !visited[r][c + 1] &&
        dp[r][c].second + 1 <= y) {
      dp[r][c + 1].first = dp[r][c].first;
      dp[r][c + 1].second = dp[r][c].second + 1;
      visited[r][c + 1] = true;
      q.push_back({r, c + 1});
    }
    if (r - 1 >= 0 && a[r - 1][c] == '.' && !visited[r - 1][c]) {
      dp[r - 1][c] = dp[r][c];
      visited[r - 1][c] = true;
      q.push_front({r - 1, c});
    }
    if (r + 1 < n && a[r + 1][c] == '.' && !visited[r + 1][c]) {
      dp[r + 1][c] = dp[r][c];
      visited[r + 1][c] = true;
      q.push_front({r + 1, c});
    }
  }
}
void solve() {
  cin >> n >> m;
  cin >> r >> c;
  cin >> x >> y;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      dp[i].resize(2001);
      cin >> a[i][j];
    }
  }
  visited[r - 1][c - 1] = true;
  bfs(r - 1, c - 1);
  int ans = 0;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < m; ++j) {
      ans += (visited[i][j] == true);
    }
  }
  cout << ans << "\n";
}
int main() {
  bool testing = false;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (testing) {
    freopen("test.txt", "rt", stdin);
    int start = clock();
    solve();
    int end = clock();
    cout << "time: " << (end - start) / (double)(CLOCKS_PER_SEC)*1000
         << " milliseconds\n";
  } else {
    solve();
  }
}
