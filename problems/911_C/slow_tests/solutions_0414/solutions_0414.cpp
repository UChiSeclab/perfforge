#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool isLeap(T y) {
  return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false);
}
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BIGMOD(T A, T B, T M = 1000000009) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T BigMod(T A, T B, T M) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
int main() {
  int Z, k1, k2, k3;
  scanf("%d%d%d", &k1, &k2, &k3);
  unordered_map<int, int> MAP;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      for (int k = 1; k <= 10; k++) {
        unordered_map<int, int> Map;
        for (int a = 0; a <= 10; a = a + k1) {
          Map[i + a] = 1;
        }
        for (int a = 0; a <= 10; a = a + k2) {
          Map[a + j] = 1;
        }
        for (int a = 0; a <= 10; a = a + k3) {
          Map[a + k] = 1;
        }
        int cnt = 0;
        for (int x = 1; x <= 10; x++) {
          if (Map[x] == 1) cnt++;
        }
        if (cnt == 10) {
          printf("YES\n");
          return 0;
        }
      }
    }
  }
  printf("NO\n");
}
