#include <bits/stdc++.h>
using namespace std;
long long int n, x, i, a, b, j;
int main() {
  cin >> n >> x;
  if (x <= n) a = a + 1;
  for (j = 2; j <= n; j++) {
    b = j * n;
    if (x % j == 0 && b >= x) {
      a++;
    }
  }
  cout << a;
  return 0;
}
