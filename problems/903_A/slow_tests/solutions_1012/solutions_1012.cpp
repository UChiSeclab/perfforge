#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:5000000000")
const unsigned long long mod = 1000000007;
long long Inf = (long long)2e9;
long long LINF = (long long)1e18 + 1e17;
using namespace std;
int main() {
  int n;
  scanf("%d", &(n));
  while (n--) {
    int x;
    scanf("%d", &(x));
    bool f = false;
    for (int i = 0; i <= 100; i++) {
      bool flag = false;
      for (int j = 0; j <= 100; j++) {
        if (i * 3 + j * 7 == x) {
          flag = 1;
          f = 1;
          break;
        }
      }
    }
    if (f)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
