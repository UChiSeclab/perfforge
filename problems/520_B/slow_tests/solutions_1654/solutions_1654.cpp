#include <bits/stdc++.h>
using namespace std;
int n, m;
int min_len = 1000000;
int reached[30000];
void addElement(int k, int m, int depth) {
  if (reached[k] != 0 && reached[k] <= depth) {
    return;
  }
  reached[k] = depth;
  if (k <= m) {
    addElement(k * 2, m, depth + 1);
  }
  if (k - 1 > 0) {
    addElement(k - 1, m, depth + 1);
  }
}
int main() {
  for (int i = 0; i < 30000; i++) {
    reached[i] = 0;
  }
  cin >> n >> m;
  addElement(n, m, 1);
  cout << reached[m] - 1;
  return 0;
}
