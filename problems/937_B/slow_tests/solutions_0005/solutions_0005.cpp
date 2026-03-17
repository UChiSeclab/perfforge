#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main() {
  int p, y;
  cin >> p >> y;
  int t = y;
  while (t > p && !is_prime(t)) --t;
  if (t == p) ++t;
  std::vector<int> div;
  for (int i = 2; i <= p && i * i <= y; ++i)
    if (is_prime(i)) div.push_back(i);
  int res = -1;
  for (int i = t; i <= y; ++i) {
    bool free = true;
    for (size_t j = 0; j < div.size(); ++j) {
      if (div[j] * div[j] > i) break;
      if (i % div[j] == 0) {
        free = false;
        break;
      }
    }
    if (free) res = i;
  }
  cout << res;
  return 0;
}
