#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int Res = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') f = (ch == '-' ? -f : f), ch = getchar();
  while (ch >= '0' && ch <= '9') Res = Res * 10 + ch - '0', ch = getchar();
  return Res * f;
}
int Ans = -2e9, N, M, H;
int Na[20][524290], Nb[20][524290];
long long L, A[150005], B[150005];
map<long long, bool> visA, visB;
int main() {
  N = read();
  H = read();
  for (int i = 1; i <= N; i++) A[i] = read(), visA[A[i]] = 1;
  M = read();
  H = read();
  for (int i = 1; i <= M; i++) {
    B[i] = read(), visB[B[i]] = 1;
    if (visA[B[i]]) Ans = 2;
  }
  sort(A + 1, A + 1 + N);
  sort(B + 1, B + 1 + M);
  L = max(B[M] - A[1], max(A[N] - B[1], max(A[N] - A[1], B[M] - B[1])));
  for (int i = 1; i <= N; i++) {
    for (long long j = 2, p = 1; j <= 2 * L && p <= 18; j <<= 1, p++)
      Na[p][A[i] % j]++;
  }
  for (int i = 1; i <= M; i++) {
    for (long long j = 2, p = 1; j <= 2 * L && p <= 18; j <<= 1, p++)
      Nb[p][B[i] % j]++;
  }
  for (int i = 1; i <= N; i++) {
    for (long long j = 2, p = 1; j <= 2 * L; j <<= 1, p++) {
      if (p <= 18)
        Ans = max(Ans, Na[p][A[i] % j] + Nb[p][(A[i] + (j >> 1)) % j]);
      else {
        int Res = 1;
        if (L / (j >> 1) < Ans) break;
        for (long long k = A[i] + (j >> 1), s = 1; k <= max(B[M], A[N]);
             k += (j >> 1), s ^= 1)
          if (s)
            Res += visB[k];
          else
            Res += visA[k];
        Ans = max(Ans, Res);
      }
    }
  }
  for (int i = 1; i <= M; i++) {
    for (long long j = 2, p = 1; j <= 2 * L; j <<= 1, p++) {
      if (p <= 18)
        Ans = max(Ans, Nb[p][B[i] % j] + Na[p][(B[i] + (j >> 1)) % j]);
      else {
        int Res = 1;
        if (L / (j >> 1) < Ans) break;
        for (long long k = B[i] + (j >> 1), s = 0; k <= max(B[M], A[N]);
             k += (j >> 1), s ^= 1)
          if (s)
            Res += visB[k];
          else
            Res += visA[k];
        Ans = max(Ans, Res);
      }
    }
  }
  printf("%d\n", Ans);
  return 0;
}
