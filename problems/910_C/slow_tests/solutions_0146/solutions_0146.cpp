#include <bits/stdc++.h>
using namespace std;
int n, p[10];
long long num[10];
char s[10];
bool canZero[10];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 10; i++) canZero[i] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = (int)strlen(s);
    canZero[s[0] - 'a'] = 0;
    for (int j = len - 1, k = 1; j >= 0; j--, k *= 10) {
      num[s[j] - 'a'] += k;
    }
  }
  for (int i = 0; i < 10; i++) p[i] = i;
  long long res = 9e18;
  do {
    if (!canZero[p[0]]) continue;
    long long loc = 0;
    for (int i = 0; i < 10; i++) {
      loc += num[p[i]] * i;
    }
    res = min(res, loc);
  } while (next_permutation(p, p + 10));
  printf("%lld", res);
  return 0;
}
