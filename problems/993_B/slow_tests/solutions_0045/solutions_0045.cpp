#include <bits/stdc++.h>
using namespace std;
int N, M;
int A[12], B[12];
int MA[12];
int MB[12];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> N >> M;
  for (i = 0; i < (N); i++) {
    cin >> x >> y;
    A[i] = (1 << x) | (1 << y);
  }
  for (i = 0; i < (M); i++) {
    cin >> x >> y;
    B[i] = (1 << x) | (1 << y);
  }
  vector<int> CA[12], CB[12];
  int a[2] = {}, b[2] = {};
  for (i = 0; i < (N); i++)
    for (j = 0; j < (M); j++)
      if (__builtin_popcount(A[i] & B[j]) == 1) MA[i] |= 1 << j;
  for (i = 0; i < (M); i++)
    for (j = 0; j < (N); j++)
      if (__builtin_popcount(B[i] & A[j]) == 1) MB[i] |= 1 << j;
  for (i = 0; i < (1200); i++) {
    for (x = 0; x < (N); x++)
      if (MA[x] == 0)
        for (y = 0; y < (M); y++) MB[y] &= ~(1 << x);
    for (x = 0; x < (M); x++)
      if (MB[x] == 0)
        for (y = 0; y < (N); y++) MA[y] &= ~(1 << x);
  }
  int cand = 0;
  int cantsure = 0;
  for (i = 0; i < (N); i++) {
    int mc = 0;
    for (j = 0; j < (M); j++)
      if ((MA[i] & (1 << j)) && (MB[j] & (1 << i))) {
        cand |= A[i] & B[j];
        mc |= A[i] & B[j];
      }
    if (__builtin_popcount(mc) > 1) return (void)printf("-1\n");
  }
  for (j = 0; j < (M); j++) {
    int mc = 0;
    for (i = 0; i < (N); i++)
      if ((MA[i] & (1 << j)) && (MB[j] & (1 << i))) {
        cand |= A[i] & B[j];
        mc |= A[i] & B[j];
      }
    if (__builtin_popcount(mc) > 1) return (void)printf("-1\n");
  }
  if (__builtin_popcount(cand) > 1) {
    (void)printf("0\n");
  } else if (__builtin_popcount(cand) == 1) {
    for (x = 0; x < (10); x++)
      if (cand & (1 << x)) cout << x << endl;
  } else {
    (void)printf("-1\n");
  }
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}
