#include <bits/stdc++.h>
using namespace std;
long long p[100000];
int main() {
  for (long long i = 1; i < 100000; i++) {
    p[i] = i * i + ((i + 1) * i) / 2;
  }
  int n;
  cin >> n;
  while (n--) {
    long long m, cnt = 0;
    cin >> m;
    for (long long i = 100000 - 1; i >= 1; i--) {
      if (p[i] <= m) {
        m -= p[i];
        cnt++;
        i++;
      }
    }
    printf("%lld\n", cnt);
  }
  return 0;
}
