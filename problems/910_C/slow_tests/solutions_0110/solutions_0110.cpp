#include <bits/stdc++.h>
const int MAXD = 10;
int A[MAXD]{};
char buff[MAXD]{};
bool lead[MAXD]{};
int sum[MAXD]{};
int N, ret = 1E9;
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf(" %s", buff);
    for (int j = strlen(buff) - 1, t = 1; j >= 0; --j, t *= MAXD)
      sum[buff[j] - 'a'] += t;
    lead[buff[0] - 'a'] = true;
  }
  std::iota(A, A + MAXD, 0);
  do {
    if (lead[A[0]]) continue;
    int res = 0;
    for (int i = 0; i < MAXD; ++i) res += i * sum[A[i]];
    ret = std::min(res, ret);
  } while (std::next_permutation(A, A + MAXD));
  printf("%d\n", ret);
  return 0;
}
