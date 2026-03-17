#include <bits/stdc++.h>
using namespace std;
long long fpow(long long n, long long k, long long p = 1000000007) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
long long inv(long long a, long long p = 1000000007) {
  return fpow(a, p - 2, p);
}
vector<long long> v[5001];
set<long long> s;
long long n, m, cap;
vector<bool> vis;
void dfs(long long cur) {
  vis[cur] = true;
  for (long long adj : v[cur]) {
    if (!vis[adj]) {
      dfs(adj);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m >> cap;
  long long x, y;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
  }
  vis = vector<bool>(n + 1, false);
  dfs(cap);
  long long count = 0;
  long long flag = 0;
  set<long long>::iterator it;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      s.insert(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (s.find(i) != s.end()) {
      vis = vector<bool>(n + 1, false);
      dfs(i);
      for (int j = 1; j <= n; j++) {
        if (vis[j] == 1 && i != j && s.find(j) != s.end()) {
          s.erase(j);
        }
      }
    }
  }
  cout << s.size() << endl;
}
