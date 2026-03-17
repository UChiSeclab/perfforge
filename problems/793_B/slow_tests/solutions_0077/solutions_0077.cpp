#include <bits/stdc++.h>
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cout << name << " = " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cout.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
using namespace std;
long long int to_ll(string& s) {
  long long int i, ret = 0, p = 1;
  for (i = (long long int)s.length() - 1; i >= 0; i--)
    ret += (s[i] - '0') * p, p *= 10LL;
  return ret;
}
long long int gcd(long long int x, long long int y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long int pwr(long long int base, long long int expo, long long int m) {
  if (base == 0) return 0LL;
  if (expo == 0) return (1LL % m);
  if ((expo & 1) == 0) {
    long long int temp = pwr(base, expo >> 1, m);
    return (temp * temp) % m;
  }
  return ((base % m) * pwr(base, expo - 1, m)) % 1000000007;
}
vector<string> v;
long long int n, m;
pair<long long int, long long int> s, t;
bool vis[1009][1009][3][4];
pair<long long int, long long int> find_pos(char ch) {
  long long int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (v[i][j] == ch) {
        pair<long long int, long long int> p = {i, j};
        return p;
      }
    }
  }
}
void dfs(long long int r, long long int c, long long int turns,
         long long int dir) {
  if (r >= n || r < 0 || c >= m || c < 0) return;
  if (turns > 2) return;
  if (vis[r][c][turns][dir] == 1) return;
  if (v[r][c] == '*') return;
  if (r == t.first && c == t.second) {
    cout << "YES\n";
    exit(0);
  }
  vis[r][c][turns][dir] = 1;
  if (dir == 0) {
    dfs(r - 1, c, turns, 0);
    dfs(r + 1, c, turns + 1, 2);
    dfs(r, c + 1, turns + 1, 1);
    dfs(r, c - 1, turns + 1, 3);
  } else if (dir == 1) {
    dfs(r - 1, c, turns + 1, 0);
    dfs(r + 1, c, turns + 1, 2);
    dfs(r, c + 1, turns, 1);
    dfs(r, c - 1, turns + 1, 3);
  } else if (dir == 2) {
    dfs(r - 1, c, turns + 1, 0);
    dfs(r + 1, c, turns, 2);
    dfs(r, c + 1, turns + 1, 1);
    dfs(r, c - 1, turns + 1, 3);
  } else if (dir == 3) {
    dfs(r - 1, c, turns + 1, 0);
    dfs(r + 1, c, turns + 1, 2);
    dfs(r, c + 1, turns + 1, 1);
    dfs(r, c - 1, turns, 3);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int i, j, sm = 0, dir;
  cin >> n >> m;
  v.resize(n);
  for (i = 0; i < n; i++) cin >> v[i];
  s = find_pos('S');
  t = find_pos('T');
  for (i = 0; i < 4; i++) {
    for (long long int p = 0; p < 1009; p++) {
      for (long long int q = 0; q < 1009; q++) {
        for (long long int x = 0; x < 3; x++) {
          for (long long int y = 0; y < 4; y++) {
            vis[p][q][x][y] = 0;
          }
        }
      }
    }
    dfs(s.first, s.second, 0, i);
  }
  cout << "NO\n";
}
