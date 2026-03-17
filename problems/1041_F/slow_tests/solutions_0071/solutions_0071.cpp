#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, Y1;
  cin >> N >> Y1;
  vector<int> v1(N);
  for (int i = 0; i < N; ++i) cin >> v1[i];
  int M, Y2;
  cin >> M >> Y2;
  vector<int> v2(M);
  for (int i = 0; i < M; ++i) cin >> v2[i];
  int res = 0;
  for (int i = 1; i <= 30; ++i) {
    map<int, int> m1;
    int p2 = (1 << i);
    for (int j = 0; j < N; ++j) ++m1[v1[j] % p2];
    map<int, int> m2;
    for (int j = 0; j < M; ++j) ++m2[v2[j] % p2];
    for (auto it = m1.begin(); it != m1.end(); ++it) {
      int cur = (*it).first;
      res = max(res, (*it).second + m2[(cur + p2 / 2) % p2]);
    }
    for (auto it = m2.begin(); it != m2.end(); ++it) {
      int cur = (*it).first;
      res = max(res, (*it).second + m1[(cur + p2 / 2) % p2]);
    }
  }
  map<int, int> m;
  for (int i = 0; i < N; ++i) {
    if (!m[v1[i]]) ++m[v1[i]];
  }
  for (int i = 0; i < M; ++i) {
    if (m[v2[i]] < 2) m[v2[i]] += 2;
  }
  bool x = false;
  for (auto it = m.begin(); it != m.end(); ++it) {
    if ((*it).second >= 2) x = true;
  }
  if (x) res = max(res, 2);
  cout << res;
}
