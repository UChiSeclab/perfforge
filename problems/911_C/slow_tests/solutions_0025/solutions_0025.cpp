#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
const long long int MOD = 1000000007;
const long double EPS = 1e-9;
int main() {
  int k1, k2, k3;
  bool light[101];
  scanf("%d %d %d\n", &k1, &k2, &k3);
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int p = 1; p <= 100; p++) {
        for (int z = 1; z <= 100; z++) {
          light[z] = false;
        }
        for (int z = i; z <= 100; z += k1) {
          light[z] = true;
        }
        for (int z = j; z <= 100; z += k2) {
          light[z] = true;
        }
        for (int z = p; z <= 100; z += k3) {
          light[z] = true;
        }
        bool finish = true;
        for (int z = 1; z <= 100; z++) {
          if (!light[z]) {
            finish = false;
            break;
          }
        }
        if (finish) {
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  printf("NO\n");
  return 0;
}
