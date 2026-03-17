#include <bits/stdc++.h>
using namespace std;
int n, k;
bool problem[16];
bool test(int msk) {
  vector<int> know(k, 0);
  int q = 0;
  for (int i = 0; i < 16; i++) {
    if (msk & (1 << i)) {
      for (int j = 0; j < 4; j++)
        if (i & (1 << j)) know[j]++;
      if (problem[i])
        ++q;
      else
        return false;
    }
  }
  if (*max_element(know.begin(), know.end()) > (q / 2)) return false;
  return true;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int msk = 0;
    for (int b, j = k - 1; j >= 0; j--) {
      cin >> b;
      if (b) msk |= (1 << j);
    }
    problem[msk] = true;
  }
  for (int i = 1; i < (1 << 16); i++) {
    if (test(i)) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
