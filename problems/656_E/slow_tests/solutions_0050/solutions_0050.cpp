#include <bits/stdc++.h>
using namespace std;
void SolveA() {
  long long r, a;
  cin >> a;
  r = 1 << a;
  cout << r << endl;
}
void EF(bool v, function<void()> f0) {
  v ? f0() : [] {}();
}
void _Eor(int n, int idx, function<void(int i)> f) {
  EF(idx < n, [&]() {
    f(idx);
    _Eor(n, idx + 1, f);
  });
}
void Eor(int n, function<void(int i)> f) { _Eor(n, 0, f); }
void SolveE() {
  int N;
  cin >> N;
  vector<vector<int>> dis(N, vector<int>(N));
  Eor(N * N, [&](int i) { cin >> dis[i / N][i % N]; });
  Eor(N, [&](int k) {
    Eor(N, [&](int i) {
      Eor(N, [&](int j) {
        EF(dis[i][k] + dis[k][j] < dis[i][j],
           [&]() { dis[i][j] = dis[i][k] + dis[k][j]; });
      });
    });
  });
  int r = 0;
  Eor(N * N, [&](int v) {
    int i = v / N;
    int j = v % N;
    EF(dis[i][j] > r, [&]() { r = dis[i][j]; });
  });
  cout << r << endl;
}
int main() {
  SolveE();
  return 0;
}
