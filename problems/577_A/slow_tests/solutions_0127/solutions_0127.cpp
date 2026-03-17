#include <bits/stdc++.h>
int main() {
  int n, x, i, a = 0;
  std::cin >> n >> x;
  for (i = n; i > 0 && x / i <= n; i--)
    if (x % i == 0) a++;
  std::cout << a;
}
