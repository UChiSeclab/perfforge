#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int main() {
  long long int a, m;
  cin >> a >> m;
  for (int i = 0; i < 1e7; i++) {
    if (a % m == 0) {
      puts("Yes");
      return 0;
    }
    a = a + (a % m);
  }
  puts("No");
  return 0;
}
