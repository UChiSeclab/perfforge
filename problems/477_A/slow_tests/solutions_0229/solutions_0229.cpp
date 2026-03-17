#include <bits/stdc++.h>
using namespace std;
int add(int a, int b) {
  a += b;
  return a % 1000000007;
}
int mlp(long long a, int b) {
  a *= b;
  return a % 1000000007;
}
int brute(int a, int b) {
  long long res(0);
  for (int i = 0; i <= 100000000; ++i) {
    if (i % b != 0 && (i / b) % (i % b) == 0 && (i / b) / (i % b) >= 1 &&
        (i / b) / (i % b) <= a) {
      res += i;
    }
  }
  return res % 1000000007;
}
void solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  int ans(0);
  for (int i(1), _l(b - 1); i <= _l; ++i) {
    int smth(mlp(add(mlp(b, i) + i, add(mlp(a, mlp(b, i)), i)), a));
    smth = mlp(smth, 500000004);
    ans = add(ans, smth);
  }
  printf("%d\n", ans);
}
int main() {
  clock_t tm = clock();
  solve();
  cerr << setprecision(3);
  cerr << (clock() - tm) / 1000000. << endl;
  return 0;
}
