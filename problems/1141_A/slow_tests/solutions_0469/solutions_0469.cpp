#include <bits/stdc++.h>
using namespace std;
map<long long int, int> level;
long long bfs(long long n, long long m) {
  int cnt = 0;
  set<long long> Q;
  set<long long>::iterator it;
  Q.insert(n);
  level[n] = 0;
  while (!Q.empty()) {
    it = Q.begin();
    cnt++;
    long long frnt = *it;
    Q.erase(it);
    long long f = 2 * frnt, s = 3 * frnt;
    if (f > m && s > m) {
      return -1;
    }
    Q.insert(f);
    Q.insert(s);
    level[f] = level[frnt] + 1;
    level[s] = level[frnt] + 1;
    if (f == m || s == m) {
      return level[f];
    }
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  if (n == m) {
    cout << 0 << endl;
    return;
  }
  cout << bfs(n, m) << endl;
  return;
}
int main() {
  solve();
  return 0;
}
