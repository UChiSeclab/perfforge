#include <bits/stdc++.h>
using namespace std;
const int D1[] = {1, 0, -1, 0}, D2[] = {0, 1, 0, -1};
int N, D;
int A[102], X[102], Y[102];
int is[202][202], minD[202][202];
bool inQ[202][202];
int maxD[102];
queue<pair<int, int> > Q;
inline bool compare(const int& i1, const int& i2) {
  if (X[i1] != X[i2]) return X[i1] < X[i2];
  return Y[i1] < Y[i2];
}
int main() {
  cin >> N >> D;
  for (int i = 2; i <= N - 1; ++i) cin >> A[i];
  for (int i = 0; i <= 200; ++i)
    for (int j = 0; j <= 200; ++j) {
      minD[i][j] = 0x3f3f3f3f;
      is[i][j] = D;
    }
  for (int i = 1; i <= N; ++i) {
    cin >> X[i] >> Y[i];
    X[i] += 100;
    Y[i] += 100;
    is[X[i]][Y[i]] = D - A[i];
  }
  minD[X[1]][Y[1]] = 0;
  Q.push(make_pair(X[1], Y[1]));
  inQ[X[1]][Y[1]] = true;
  while (!Q.empty()) {
    pair<int, int> now = Q.front();
    Q.pop();
    inQ[now.first][now.second] = false;
    for (int k = 0; k < 4; ++k)
      if (now.first + D1[k] >= 0 && now.first + D1[k] <= 200 &&
          now.second + D2[k] >= 0 && now.second + D2[k] <= 200 &&
          minD[now.first][now.second] + is[now.first][now.second] <
              minD[now.first + D1[k]][now.second + D2[k]]) {
        minD[now.first + D1[k]][now.second + D2[k]] =
            minD[now.first][now.second] + is[now.first][now.second];
        if (!inQ[now.first + D1[k]][now.second + D2[k]]) {
          Q.push(make_pair(now.first + D1[k], now.second + D2[k]));
          inQ[now.first + D1[k]][now.second + D2[k]] = true;
        }
      }
  }
  cout << minD[X[N]][Y[N]] << '\n';
}
