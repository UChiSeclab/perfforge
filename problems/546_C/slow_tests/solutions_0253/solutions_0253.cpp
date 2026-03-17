#include <bits/stdc++.h>
using namespace std;
int main() {
  int j, n, a, b, k, c;
  long int i;
  queue<int> v1;
  queue<int> v2;
  cin >> n;
  cin >> a;
  while (a--) {
    cin >> k;
    v1.push(k);
  }
  cin >> b;
  while (b--) {
    cin >> k;
    v2.push(k);
  }
  for (i = 0;; i++) {
    if (v1.empty()) {
      printf("%ld 2\n", i);
      return 0;
    }
    if (v2.empty()) {
      printf("%ld 1\n", i);
      ;
      return 0;
    }
    if (i > 40000000) {
      printf("-1\n");
      return 0;
    }
    a = v1.front();
    v1.pop();
    b = v2.front();
    v2.pop();
    if (a > b) {
      v1.push(b);
      v1.push(a);
    } else {
      v2.push(a);
      v2.push(b);
    }
  }
  return 0;
}
