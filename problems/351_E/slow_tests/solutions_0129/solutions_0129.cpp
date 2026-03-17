#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const long long mod = 1000 * 1000 * 1000 + 7;
const int maxn = 2010;
long long DP[2][maxn];
int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  vector<int> I(N);
  for (int i = (int)(0); i < (int)(N); i++) {
    cin >> P[i];
    I[i] = i;
  }
  for (int i = (int)(0); i < (int)(N); i++)
    for (int j = (int)(0); j < (int)(N - 1); j++) {
      if (abs(P[j]) > abs(P[j + 1])) {
        swap(P[j], P[j + 1]);
        swap(I[j], I[j + 1]);
      }
    }
  long long ans = 0;
  int pos = 0;
  while (pos < N) {
    int npos = pos;
    while (npos < N && abs(P[npos]) == abs(P[pos])) npos++;
    int M = npos - pos;
    vector<long long> L(M, 0);
    vector<long long> U(M, 0);
    for (int i = (int)(0); i < (int)(M); i++) {
      for (int j = (int)(0); j < (int)(pos); j++) {
        if (I[j] < I[pos + i]) {
          L[i]++;
        } else {
          U[i]++;
        }
      }
    }
    fill(&DP[0][0], &DP[0][0] + 2 * maxn, inf);
    DP[0][0] = 0;
    for (int i = (int)(0); i < (int)(M); i++) {
      int cur = i % 2;
      int nxt = 1 - cur;
      fill(&DP[nxt][0], &DP[nxt][0] + maxn, inf);
      for (int j = (int)(0); j < (int)(i + 1); j++)
        if (DP[cur][j] < inf) {
          DP[nxt][j] = min(DP[nxt][j], DP[cur][j] + L[i] + j);
          DP[nxt][j + 1] = min(DP[nxt][j + 1], DP[cur][j] + U[i]);
        }
    }
    if (P[pos] != 0) {
      long long add = 1e12;
      for (int i = (int)(0); i < (int)(M + 1); i++)
        add = min(add, DP[M % 2][i]);
      ans += add;
    }
    pos = npos;
  }
  cout << ans << endl;
}
