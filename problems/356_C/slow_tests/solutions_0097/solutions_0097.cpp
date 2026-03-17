#include <bits/stdc++.h>
using namespace std;
int N;
int Ai[1000010];
int F[5], E[5];
void read();
void solve();
int main() {
  read();
  solve();
  return 0;
}
void read() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> Ai[i];
}
void solve() {
  int sum = accumulate(&Ai[0], &Ai[N], 0), res = sum;
  stable_sort(&Ai[0], &Ai[N]);
  for (int i = 0; i < N; ++i) ++F[Ai[i]];
  for (int i = 0; i < N; ++i) {
    int ereq = E[1] + 2 * E[2] + 3 * E[3] + 4 * E[4];
    int favl = F[4];
    int freq = 2 * F[1] + F[2];
    int ftsp = 3 * F[1] + 2 * F[2] + F[3];
    if (ftsp >= ereq && ereq + favl >= freq) res = min(res, max(freq, ereq));
    --F[Ai[i]], ++E[Ai[i]];
  }
  cout << (res < sum ? res : -1) << "\n";
}
