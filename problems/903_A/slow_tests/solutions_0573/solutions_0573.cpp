#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  int n;
  std::cin >> n;
  while (n-- > 0) {
    int x;
    std::cin >> x;
    bool flag = false;
    for (int i = 0; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        int t = 3 * i + 7 * j;
        if (t == x) flag = true;
      }
    }
    if (flag)
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}
