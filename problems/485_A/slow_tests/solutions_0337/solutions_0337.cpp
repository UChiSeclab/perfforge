#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
long long a, m;
int main() {
  scanf("%lld%lld", &a, &m);
  int sum = 0;
  while (sum <= 1e7) {
    if (a % m == 0) return 0 * puts("Yes");
    a = a + a % m;
    sum++;
  }
  puts("No");
}
